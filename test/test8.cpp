#include <cassert>
#include <type_pack.hpp>
#include <type_traits>

int main() {
  using types = tp::type_pack<void, float, char, char, bool, char>;

  assert((tp::count<char, types>::value == 3));
  assert((tp::count<void, types>::value == 1));
  assert((tp::count<int, types>::value == 0));

  assert((tp::count_if<std::is_void, types>::value == 1));
  assert((tp::count_if<std::is_integral, types>::value == 4));
  assert((tp::count_if<std::is_const, types>::value == 0));
  assert((tp::count_if<std::is_floating_point, types>::value == 1));

  using empty = tp::empty_pack;

  assert((tp::count<int, empty>::value == 0));
  assert((tp::count_if<std::is_integral, empty>::value == 0));

  using ints = tp::generate_t<10, int>;

  assert((tp::count<int, ints>::value == 10));

  return 0;
}
