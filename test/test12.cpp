#include <cassert>
#include <type_pack.hpp>
#include <type_traits>

template <typename T, bool False>
void static_typename() {
  static_assert(False, "Type:");
}

int main() {
  {
    using types = tp::type_pack<int, float, double, short>;
    using floats = tp::copy_t<types, 1, 3>;
    using same = tp::copy_t<types, 0, types::size()>;
    using until_end = tp::copy_t<types, 1, 4>;
    using empty = tp::copy_t<types, 1, 1>;
    using last = tp::copy_t<types, types::size() - 1, types::size()>;

    assert((floats {} == tp::type_pack<float, double> {}));
    assert((until_end {} == tp::type_pack<float, double, short> {}));
    assert(same {} == types {});
    assert(empty {} == tp::empty_pack {});
    assert(last {} == tp::type_pack<short> {});
  }

  {
    using types = tp::type_pack<int, float, char, double, short, void>;
    using ints = tp::copy_if_t<types, std::is_integral>;
    using floats = tp::copy_if_t<types, std::is_floating_point>;
    using empty = tp::copy_if_t<types, std::is_function>;

    assert((ints {} == tp::type_pack<int, char, short> {}));
    assert((floats {} == tp::type_pack<float, double> {}));
    assert(empty {} == tp::empty_pack {});
  }

  {
    using empty = tp::copy_if_t<tp::empty_pack, std::is_integral>;

    assert(empty {} == tp::empty_pack {});
  }

  {
    using pc_less = tp::part_caller<tp::sizeof_more, long>;

    using types = tp::type_pack<bool, char, short, int, long, long long>;
    using less_long = tp::copy_if_t<types, pc_less::type>;

    assert((less_long {} == tp::type_pack<bool, char, short, int> {}));
  }

  return 0;
}
