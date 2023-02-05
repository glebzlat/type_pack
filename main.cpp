#include "type_pack.hpp"
#include <cassert>
#include <sstream>
#include <stdexcept>

template <typename T>
inline std::string get_name() {
  char const* str = __PRETTY_FUNCTION__;
  while (*str != '=') ++str;
  str += 2;
  std::size_t size = 0;
  while (str[size] != ';' && str[size] != ']') ++size;
  return std::string(str, size);
}

template <typename T, typename U>
inline void assert_is_same() {
  if (std::is_same<T, U>::value) return;

  std::ostringstream os;
  os << "Assertion \'assert_is_same\' failed: types \'" << get_name<T>()
     << "\' and \'" << get_name<U>() << "\' are not the same\n";

  throw std::runtime_error(os.str());
}

int main() {
  assert_is_same<typename tp::just_type<int>::type, int>();

  // Test 1: head and tail, relation operators, is_equal, is_not_equal
  {
    using test_tp = tp::type_pack<int, float, double>;

    assert_is_same<typename tp::head<test_tp>::type, int>();

    assert_is_same<tp::tail<test_tp>::type, tp::type_pack<float, double>>();

    assert((tp::is_equal<tp::type_pack<int>, tp::type_pack<int>>::value));
    assert((tp::type_pack<int, float> {} == tp::type_pack<int, float> {}));

    assert((tp::is_not_equal<tp::type_pack<int>, tp::type_pack<float>>::value));
    assert((tp::type_pack<int, float> {} != tp::type_pack<float, int> {}));

    assert((tp::is_equal<tp::just_type<int>, tp::just_type<int>>::value));
    assert((tp::is_equal<tp::just_type<float>, tp::type_pack<float>>::value));

    assert((tp::is_not_equal<tp::just_type<bool>,
                             tp::type_pack<bool, int>>::value));
  }

  // Test 2: concatenate
  {
    using integer = tp::type_pack<int>;
    using floating = tp::type_pack<float>;
    using intnfloat = decltype(integer {} + floating {});
    using intnfloat1 = typename tp::concatenate<integer, floating>::type;

    assert_is_same<intnfloat, tp::type_pack<int, float>>();
    assert_is_same<intnfloat, intnfloat1>();

    using i = tp::type_pack<int, long>;
    using u = tp::just_type<unsigned>;
    using c = tp::type_pack<char>;
    using ints = typename tp::concatenate<i, u, c>::type;

    assert_is_same<ints, tp::type_pack<int, long, unsigned, char>>();

    using b1 = tp::just_type<bool>;
    using b2 = tp::just_type<bool>;
    using b3 = tp::just_type<bool>;

    assert_is_same<tp::concatenate_t<b1, b2, b3>,
                   tp::type_pack<bool, bool, bool>>();
  }

  // Test 3: pop_front_t, pop_back_t, push_front_t, push_back_t
  {
    using ts = tp::type_pack<float, short, int, double>;
    using ts1 = tp::pop_front_t<ts>;

    assert_is_same<ts1, tp::type_pack<short, int, double>>();

    using ints = tp::pop_back_t<ts1>;

    assert_is_same<ints, tp::type_pack<short, int>>();

    using ints1 = tp::push_front_t<char, ints>;

    assert_is_same<ints1, tp::type_pack<char, short, int>>();

    using ints2 = tp::push_back_t<long, ints1>;

    assert_is_same<ints2, tp::type_pack<char, short, int, long>>();
  }

  // Test 4:: contains, find
  {
    using integrals = tp::type_pack<int, char, short, unsigned, bool>;

    assert((tp::contains<bool, integrals>::value));

    assert((tp::contains<float, integrals>::value == false));

    assert((tp::find<short, integrals>::value == 2));

    assert((tp::find<double, integrals>::value == 5));
  }

  // Test 5: part_caller, find_if
  {
    struct Base {};

    struct Derived : Base {};

    using types = tp::type_pack<void, int, float, Derived>;

    assert((tp::find_if<std::is_void, types>::value == 0));

    using pc_is_bool = tp::part_caller<std::is_same, bool>;
    assert((tp::find_if<pc_is_bool::type, types>::value == 4));

    using pc_base_of = tp::part_caller<std::is_base_of, Base>;
    assert((tp::find_if<pc_base_of::type, types>::value == 3));
  }

  // Test 6: any_of, none_of
  {
    using types = tp::type_pack<void, int, float>;

    assert((tp::any_of<std::is_void, types>::value));

    assert((tp::none_of<std::is_void, types>::value == false));

    assert((tp::none_of<std::is_const, types>::value));
  }

  {
    using types = tp::type_pack<bool, char, short, int, long>;

    assert_is_same<typename tp::at<1, types>::type, char>();
    assert_is_same<tp::at_t<0, types>, bool>();
    assert_is_same<tp::at_t<4, types>, long>();
  }

  {
    using seq = tp::generate_t<5, int>;

    assert(seq::size() == 5);

    using empty_seq = tp::generate_t<0, int>;

    assert(empty_seq::size() == 0);
    assert(empty_seq::empty());
  }

  {
    using types = tp::type_pack<void, float, char, char, bool, char>;

    assert((tp::count<char, types>::value == 3));

    assert((tp::count_if<std::is_void, types>::value == 1));

    assert((tp::count_if<std::is_integral, types>::value == 4));

    assert((tp::count_if<std::is_const, types>::value == 0));
  }

  {
    using types = tp::type_pack<void, int, void, bool, void, float>;

    using no_first_void = tp::remove_t<void, types>;

    assert_is_same<no_first_void,
                   tp::type_pack<int, void, bool, void, float>>();

    using no_void = tp::remove_all_t<void, types>;

    assert_is_same<no_void, tp::type_pack<int, bool, float>>();
  }

  {
    using types = tp::type_pack<int, int, char, char, bool, bool, bool>;
    using no_dup = tp::no_duplicates_t<types>;

    assert_is_same<no_dup, tp::type_pack<int, char, bool>>();

    assert_is_same<tp::no_duplicates_t<no_dup>,
                   tp::type_pack<int, char, bool>>();

    using types1 = tp::type_pack<int, char, bool, int, char, bool, void>;
    using no_dup1 = tp::no_duplicates_t<types1>;

    assert_is_same<no_dup1, tp::type_pack<int, char, bool, void>>();

    assert_is_same<tp::no_duplicates_t<tp::empty_pack>, tp::empty_pack>();
  }

  {
    using floats = tp::type_pack<float, float, float>;
    using ints = tp::replace_t<float, int, floats>;

    assert_is_same<ints, tp::type_pack<int, int, int>>();

    using with_void = tp::type_pack<void, bool, void, int, void>;
    using without_void = tp::replace_t<void, char, with_void>;

    assert_is_same<without_void, tp::type_pack<char, bool, char, int, char>>();

    assert_is_same<tp::replace_t<float, int, tp::empty_pack>, tp::empty_pack>();
  }

  return 0;
}
