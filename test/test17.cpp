#include <cassert>
#include <type_pack.hpp>
#include <type_traits>

struct Base {};

struct Derived1 : Base {};

struct Derived2 : Base {};

struct Derived3 : Derived1 {};

struct Other {};

int main() {
  assert((tp::base_is_less<Base, Derived1>::value));
  assert((tp::base_is_less<Base, Derived2>::value));
  assert((tp::base_is_less<Base, Derived3>::value));

  assert((tp::base_is_less<Derived1, Derived3>::value));
  assert((tp::base_is_less<Derived1, Derived2>::value == false));

  assert((tp::base_is_less<Derived1, Base>::value == false));
  assert((tp::base_is_less<Derived2, Base>::value == false));

  assert((tp::base_is_less<Base, Base>::value == false));
  assert((tp::base_is_less<Derived1, Derived1>::value == false));

  assert((tp::base_is_less<Base, Other>::value == false));
  assert((tp::base_is_less<Other, Base>::value == false));

  assert((tp::base_is_less<Derived1, Other>::value == false));
  assert((tp::base_is_less<Other, Derived1>::value == false));

  assert((tp::derived_is_less<Derived1, Base>::value));
  assert((tp::derived_is_less<Derived2, Base>::value));
  assert((tp::derived_is_less<Derived3, Base>::value));

  assert((tp::derived_is_less<Derived3, Derived1>::value));
  assert((tp::derived_is_less<Derived2, Derived1>::value == false));

  assert((tp::derived_is_less<Base, Derived1>::value == false));
  assert((tp::derived_is_less<Base, Derived2>::value == false));

  assert((tp::derived_is_less<Base, Base>::value == false));
  assert((tp::derived_is_less<Derived1, Derived1>::value == false));

  assert((tp::derived_is_less<Base, Other>::value == false));
  assert((tp::derived_is_less<Other, Base>::value == false));

  assert((tp::derived_is_less<Derived1, Other>::value == false));
  assert((tp::derived_is_less<Other, Derived1>::value == false));

  return 0;
}
