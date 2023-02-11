#include <cassert>
#include <type_pack.hpp>
#include <type_traits>

struct Base {};

struct Derived : Base {};

int main() {
  using types = tp::type_pack<Derived, void, int, Derived, bool, Derived, void>;

  assert((tp::find_if<std::is_void, types>::value == 1));
  assert((tp::find_if<std::is_void, types, 2>::value == 6));
  assert((tp::find_if<std::is_void, types, 6>::value == 6));

  assert((tp::find_if<std::is_floating_point, types>::value == types::size()));

  using pc_is_bool = tp::part_caller<std::is_same, bool>;

  assert((tp::find_if<pc_is_bool::type, types>::value == 4));

  using pc_derived = tp::part_caller<std::is_base_of, Base>;

  assert((tp::find_if<pc_derived::type, types>::value == 0));
  assert((tp::find_if<pc_derived::type, types, 1>::value == 3));
  assert((tp::find_if<pc_derived::type, types, 3>::value == 3));
  assert((tp::find_if<pc_derived::type, types, 4>::value == 5));

  assert((tp::find_if<std::is_const, tp::empty_pack>::value ==
          tp::empty_pack::size()));

  return 0;
}
