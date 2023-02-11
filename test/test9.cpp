#include <cassert>
#include <type_pack.hpp>
#include <type_traits>

int main() {
  using types = tp::type_pack<void, int, void, bool, void, float>;
  using no_first_void_expected = tp::type_pack<int, void, bool, void, float>;
  using no_void_expected = tp::type_pack<int, bool, float>;

  {
    using no_first_void = tp::remove_t<void, types>;

    assert((std::is_same<no_first_void, no_first_void_expected>::value));

    using no_void = tp::remove_all_t<void, types>;

    assert((std::is_same<no_void, no_void_expected>::value));
    assert((no_void {} == no_void_expected {}));
  }

  {
    using no_first_void = tp::remove_if_t<std::is_void, types>;

    assert((std::is_same<no_first_void, no_first_void_expected>::value));

    using no_void = tp::remove_all_if_t<std::is_void, types>;

    assert((std::is_same<no_void, no_void_expected>::value));
    assert((no_void {} == no_void_expected {}));
  }

  {
    using empty = tp::empty_pack;

    assert((tp::remove_t<int, empty> {} == tp::empty_pack {}));
    assert((tp::remove_all_t<int, empty> {} == tp::empty_pack {}));
    assert((tp::remove_if_t<std::is_integral, empty> {} == tp::empty_pack {}));
    assert(
        (tp::remove_all_if_t<std::is_integral, empty> {} == tp::empty_pack {}));
  }

  return 0;
}
