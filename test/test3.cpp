#include <cassert>
#include <type_pack.hpp>
#include <type_traits>

int main() {
  using types = tp::type_pack<float, short, int, double>;

  using ts1 = tp::pop_front_t<types>;
  using ts2 = tp::pop_back_t<ts1>;

  assert((std::is_same<ts2, tp::type_pack<short, int>>::value));

  using ints1 = tp::push_front_t<char, ts2>;
  using ints2 = tp::push_back_t<long, ints1>;

  assert((std::is_same<ints2, tp::type_pack<char, short, int, long>>::value));

  return 0;
}
