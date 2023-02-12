#include <cassert>
#include <type_pack.hpp>
#include <type_traits>

struct Base {};

struct Derived1 : Base {};

struct Derived2 : Base {};

struct Derived3 : Derived1 {};

struct Other {};

int main() {
  {
    using types = tp::type_pack<Base, Derived1, Derived2, Derived3>;

    using max_derived = tp::max_t<types, tp::base_is_less>;
    using max_base = tp::max_t<types, tp::derived_is_less>;
    using min_base = tp::min_t<types, tp::base_is_less>;
    using min_derived = tp::min_t<types, tp::derived_is_less>;

    assert((std::is_same<max_derived, Derived3>::value));
    assert((std::is_same<max_base, Base>::value));
    assert((std::is_same<min_base, Base>::value));
    assert((std::is_same<min_derived, Derived3>::value));
  }

  {
    using types = tp::type_pack<Derived1, Derived3, Derived2, Other>;

    using max_derived = tp::max_t<types, tp::base_is_less>;
    using max_base = tp::max_t<types, tp::derived_is_less>;
    using min_base = tp::min_t<types, tp::base_is_less>;
    using min_derived = tp::min_t<types, tp::derived_is_less>;

    assert((std::is_same<max_derived, Derived3>::value));
    assert((std::is_same<max_base, Derived1>::value));
    assert((std::is_same<min_base, Other>::value));
    assert((std::is_same<min_derived, Other>::value));
  }

  {
    using types = tp::generate_t<5, Derived1>;

    using max_derived = tp::max_t<types, tp::base_is_less>;
    using max_base = tp::max_t<types, tp::derived_is_less>;
    using min_base = tp::min_t<types, tp::base_is_less>;
    using min_derived = tp::min_t<types, tp::derived_is_less>;

    assert((std::is_same<max_derived, Derived1>::value));
    assert((std::is_same<max_base, Derived1>::value));
    assert((std::is_same<min_base, Derived1>::value));
    assert((std::is_same<min_derived, Derived1>::value));
  }

  {
    using types = tp::type_pack<int, long, int, int, char>;

    using min_size = tp::min_t<types, tp::sizeof_less>;
    using max_size = tp::max_t<types, tp::sizeof_less>;

    assert((std::is_same<min_size, char>::value));
    assert((std::is_same<max_size, long>::value));
  }

  {
    using types = tp::empty_pack;

    using min = tp::min_t<types, tp::base_is_less>;
    using max = tp::max_t<types, tp::base_is_less>;

    assert((std::is_same<min, tp::empty_type>::value));
    assert((std::is_same<max, tp::empty_type>::value));
  }

  return 0;
}
