#include <cassert>
#include <type_pack.hpp>
#include <type_traits>

int main() {
  {
    using floats = tp::type_pack<float, float, float>;
    using ints = tp::replace_t<float, int, floats>;

    assert((ints {} == tp::type_pack<int, int, int> {}));
  }

  {
    using types = tp::type_pack<int, void, char, void, int, void>;
    using no_void = tp::replace_t<void, bool, types>;

    assert((no_void {} == tp::type_pack<int, bool, char, bool, int, bool> {}));
  }

  {
    using types = tp::type_pack<bool, char, short, int>;
    using same = tp::replace_t<float, long, types>;

    assert(same {} == types {});
  }

  {
    using empty = tp::empty_pack;
    assert((tp::replace_t<void, int, empty> {} == tp::empty_pack {}));
  }

  {
    using floats = tp::generate_t<10, float>;
    using ints = tp::generate_t<10, int>;

    assert((tp::replace_t<float, int, floats> {} == ints {}));
  }

  return 0;
}
