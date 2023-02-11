#include <cassert>
#include <type_pack.hpp>
#include <type_traits>

int main() {
  {
    using types = tp::type_pack<bool, char, short, int, long>;

    assert((std::is_same<tp::at_t<0, types>, bool>::value));
    assert((std::is_same<tp::at_t<1, types>, char>::value));
    assert((std::is_same<tp::at_t<2, types>, short>::value));
    assert((std::is_same<tp::at_t<3, types>, int>::value));
    assert((std::is_same<tp::at_t<4, types>, long>::value));

    /*
     * error: In template: implicit instantiation of undefined template
     * 'tp::__details::Error_Type_Pack_Out_Of_Range<tp::type_pack<>>'
     */
    // assert((std::is_same<tp::at_t<5, types>, long>::value));
  }

  {
    using seq = tp::generate_t<5, int>;

    assert(seq::size() == 5);

    assert((std::is_same<tp::at_t<0, seq>, int>::value));
    assert((std::is_same<tp::at_t<4, seq>, int>::value));

    using empty = tp::generate_t<0, int>;

    assert(empty::size() == 0);
    assert(empty::empty());

    assert((std::is_same<empty, tp::empty_pack>::value));
  }

  return 0;
}
