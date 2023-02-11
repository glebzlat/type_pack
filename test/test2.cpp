#include <cassert>
#include <type_pack.hpp>
#include <type_traits>

int main() {
  using int_t = tp::type_pack<int>;
  using float_t = tp::just_type<float>;

  using intfloat = tp::concatenate_t<int_t, float_t>;
  using intfloat1 = decltype(int_t {} + float_t {});

  assert((std::is_same<intfloat, intfloat1>::value));

  using t1 = tp::just_type<bool>;
  using t2 = tp::just_type<char>;
  using t3 = tp::just_type<short>;

  using small_ints = tp::concatenate_t<t1, t2, t3>;

  assert((std::is_same<small_ints, tp::type_pack<bool, char, short>>::value));

  return 0;
}
