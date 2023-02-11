#include <cassert>
#include <type_pack.hpp>
#include <type_traits>

int main() {
  using types = tp::type_pack<void, int, float>;

  assert((tp::any_of<std::is_void, types>::value));
  assert((tp::any_of<std::is_integral, types>::value));
  assert((tp::any_of<std::is_floating_point, types>::value));

  assert((tp::any_of<std::is_pointer, types>::value == false));

  assert((tp::all_of<std::is_fundamental, types>::value));
  assert((tp::all_of<std::is_const, types>::value == false));

  assert((tp::none_of<std::is_array, types>::value));
  assert((tp::none_of<std::is_void, types>::value == false));

  assert((tp::none_of<std::is_integral, tp::empty_pack>::value));
  assert((tp::any_of<std::is_integral, tp::empty_pack>::value == false));
  assert((tp::all_of<std::is_integral, tp::empty_pack>::value == true));

  return 0;
}
