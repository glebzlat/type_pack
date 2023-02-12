#include <cassert>
#include <type_pack.hpp>
#include <type_traits>

int main() {
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

  return 0;
}
