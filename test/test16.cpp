#include <cassert>
#include <type_pack.hpp>
#include <type_traits>

template <typename T, bool False>
void stc() {
  static_assert(False, "");
}

int main() {
  {
    using types = tp::type_pack<char, short, int, long, long long>;

    assert((tp::is_sorted<types, tp::sizeof_less>::value));
    assert((tp::is_sorted<types, tp::sizeof_more>::value == false));
  }
  {
    using types = tp::type_pack<int, char, long, char, short, long>;
    using sorted = tp::sort_t<types, tp::sizeof_less>;
    using sorted_gt = tp::sort_t<types, tp::sizeof_more>;

    // stc<sorted, false>();

    assert((tp::is_sorted<sorted, tp::sizeof_less>::value));
    assert((tp::is_sorted<types, tp::sizeof_less>::value == false));
    assert((tp::is_sorted<sorted, tp::sizeof_more>::value == false));
    assert((tp::is_sorted<sorted_gt, tp::sizeof_more>::value));
    assert((tp::is_sorted<sorted_gt, tp::sizeof_less>::value == false));
  }
  {
    using types = tp::generate_t<10, int>;

    assert((tp::is_sorted<types, tp::sizeof_less>::value));
  }
  {
    using type = tp::type_pack<int>;

    assert((tp::is_sorted<type, tp::sizeof_less>::value));
  }
  {
    using empty = tp::empty_pack;

    assert((tp::is_sorted<empty, tp::sizeof_less>::value));
    assert((tp::is_sorted<empty, tp::sizeof_more>::value));
  }
  return 0;
}
