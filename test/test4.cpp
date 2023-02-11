#include <cassert>
#include <type_pack.hpp>
#include <type_traits>

int main() {
  {
    using integrals = tp::type_pack<int, char, short, unsigned, bool>;

    assert((tp::contains<bool, integrals>::value));

    assert((tp::contains<float, integrals>::value == false));

    assert((tp::find<short, integrals>::value == 2));

    assert((tp::find<double, integrals>::value == integrals::size()));
  }

  {
    using types = tp::type_pack<int, void, char, bool, void, float>;

    assert((tp::find<void, types>::value == 1));
    assert((tp::find<void, types, 2>::value == 4));
    assert((tp::find<void, types, 3>::value == 4));
    assert((tp::find<void, types, 4>::value == 4));
    assert((tp::find<void, types, 5>::value == types::size()));

    assert((tp::find<int, tp::empty_pack>::value == tp::empty_pack::size()));
  }
  return 0; 
}
