#include <cassert>
#include <type_pack.hpp>
#include <type_traits>

int main() {
  {
    using types = tp::type_pack<int, int, char, char, bool, bool, bool>;
    using unique = tp::unique_t<types>;

    assert((unique {} == tp::type_pack<int, char, bool> {}));
    assert((tp::unique_t<unique> {} == tp::type_pack<int, char, bool> {}));
  }

  {
    using types = tp::generate_t<10, int>;
    using unique = tp::unique_t<types>;

    assert(unique {} == tp::type_pack<int> {});
    assert(tp::unique_t<unique> {} == tp::type_pack<int> {});
  }

  return 0;
}
