#include <type_pack.hpp>
#include <cassert>
#include <type_traits>

int main() {
  assert((std::is_same<typename tp::just_type<int>::type, int>::value));

  assert(tp::empty_pack::size() == 0);
  assert(tp::empty_pack::empty());

  using types = tp::type_pack<char, short, int>;

  assert((std::is_same<tp::head_t<types>, char>::value));

  using tail = tp::tail_t<types>;

  assert((std::is_same<tp::head_t<tail>, short>::value));

  using last = tp::tail_t<tail>;

  assert(last::size() == 1);
  assert((std::is_same<tp::head_t<last>, int>::value));

  using empty = tp::tail_t<last>;

  assert(empty::empty());
}
