#include <cassert>
#include <type_pack.hpp>
#include <type_traits>

int main() {
  {
    using sequence1 = tp::type_pack<int, int, char, int>;
    using sequence2 = tp::type_pack<int, int, int, int>;

    assert((tp::lexicographical_compare<sequence1, sequence2,
                                        tp::sizeof_less>::value));
    assert((tp::lexicographical_compare<sequence2, sequence1,
                                        tp::sizeof_less>::value == false));
    assert((tp::lexicographical_compare<sequence2, sequence2,
                                        tp::sizeof_less>::value == false));
  }

  {
    using shorter = tp::generate_t<3, int>;
    using longer = tp::generate_t<4, int>;

    assert(
        (tp::lexicographical_compare<shorter, longer, tp::sizeof_less>::value));

    assert(
        (tp::lexicographical_compare<longer, shorter, tp::sizeof_less>::value ==
         false));
  }

  {
    using empty = tp::empty_pack;
    using non_empty = tp::type_pack<int>;

    assert((tp::lexicographical_compare<empty, empty, tp::sizeof_less>::value ==
            false));
    assert((
        tp::lexicographical_compare<empty, non_empty, tp::sizeof_less>::value));
  }

  {
    struct Base {};

    struct Derived : Base {};

    struct Other {};

    using sequence1 = tp::type_pack<Base, Base, Base, Base>;
    using sequence2 = tp::type_pack<Base, Base, Derived, Base>;
    using sequence3 = tp::type_pack<Base, Base, Other, Base>;
    using sequence4 = tp::type_pack<Base, Base, int, Base>;

    assert((tp::lexicographical_compare<sequence1, sequence2,
                                        tp::base_is_less>::value));
    assert((tp::lexicographical_compare<sequence2, sequence1,
                                        tp::derived_is_less>::value));

    assert((tp::lexicographical_compare<sequence3, sequence1,
                                        tp::base_is_less>::value == false));
    assert((tp::lexicographical_compare<sequence1, sequence3,
                                        tp::base_is_less>::value == false));
    assert((tp::lexicographical_compare<sequence3, sequence2,
                                        tp::derived_is_less>::value == false));
    assert((tp::lexicographical_compare<sequence2, sequence3,
                                        tp::derived_is_less>::value == false));

    assert((tp::lexicographical_compare<sequence1, sequence4,
                                        tp::base_is_less>::value == false));
    assert((tp::lexicographical_compare<sequence2, sequence4,
                                        tp::base_is_less>::value == false));
    assert((tp::lexicographical_compare<sequence4, sequence2,
                                        tp::derived_is_less>::value == false));
  }

  {
    struct Base {};

    struct Derived : Base {};

    struct Other {};

    using sequence1 = tp::type_pack<Base, Base, Base>;
    using sequence2 = tp::type_pack<Base, Derived, Base>;
    using sequence3 = tp::type_pack<Base, Other, Derived>;

    assert((tp::lexicographical_compare<sequence1, sequence3,
                                        tp::base_is_less>::value));
    assert((tp::lexicographical_compare<sequence3, sequence2,
                                        tp::derived_is_less>::value));
    assert((tp::lexicographical_compare<sequence2, sequence3,
                                        tp::base_is_less>::value));
  }

  return 0;
}
