#include <cassert>
#include <type_pack.hpp>
#include <type_traits>

int main() {
  {
    using types = tp::type_pack<long, int, long long, short, bool>;
    using sorted = tp::sort_t<types, tp::sizeof_less>;

    assert((sorted {} == tp::type_pack<bool, short, int, long, long long> {}));
  }

  {
    using types = tp::type_pack<int, int, short, int, short, short>;
    using sorted = tp::sort_t<types, tp::sizeof_less>;

    assert((sorted {} == tp::type_pack<short, short, short, int, int, int> {}));
  }

  {
    using types = tp::generate_t<5, int>;
    using sorted = tp::sort_t<types, tp::sizeof_less>;

    assert(sorted {} == types {});
  }

  {
    using types = tp::type_pack<int, char>;
    using sorted = tp::sort_t<types, tp::sizeof_less>;

    assert((sorted {} == tp::type_pack<char, int> {}));
  }

  {
    using types = tp::type_pack<int, char>;
    using sorted = tp::sort_t<types, tp::sizeof_more>;

    assert((sorted {} == tp::type_pack<int, char> {}));
  }

  {
    using empty = tp::empty_pack;
    using result = tp::sort_t<empty, tp::sizeof_less>;

    assert(result {} == tp::empty_pack {});
  }

  {
    using types = tp::type_pack<char, int, long>;
    using sorted = tp::sort_t<types, tp::sizeof_more>;

    assert((sorted {} == tp::type_pack<long, int, char> {}));
  }

  {
    using types = tp::type_pack<int, char, int>;
    using sorted = tp::sort_t<types, tp::sizeof_less>;

    assert((sorted {} == tp::type_pack<char, int, int> {}));
  }

  {
    using types = tp::type_pack<int>;
    using sorted = tp::sort_t<types, tp::sizeof_less>;

    assert((sorted {} == tp::type_pack<int> {}));
  }

  return 0;
}
