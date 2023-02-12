namespace tp {
  /**
   * @struct is_equal
   * @brief Checks if the two type_packs or just_types is equal
   *
   * @tparam T left operand
   * @tparam U right operand
   *
   * Operation compares just_type with just_type, type_pack with type_pack and
   * type_pack with just_type. The last comparsion is only allowed to type_pack,
   * which has only one type. Provides the member constant `value` that is equal
   * to `true` if the types are equal, otherwise `false`. `is_equal` inherits
   * `std::integral_constant` members.
   *
   * Implementation
   *
   * @snippet type_pack.hpp isequalimpl
   */

  /**
   * @struct is_not_equal
   * @brief Checks if the two type_packs or just_types is not equal
   *
   * @tparam T left operand
   * @tparam U right operand
   *
   * Operation compares just_type with just_type, type_pack with type_pack and
   * type_pack with just_type. The last comparsion is only allowed to type_pack,
   * which has only one type. Provides the member constant `value` that is equal
   * to `true` if the types are not equal, otherwise `false`. `is_not_equal`
   * inherits `std::integral_constant` members.
   */

  /**
   * @struct lexicographical_compare
   * @brief Returns true if one type_pack is lexicographically less than another
   *
   * @tparam TP1 first type_pack
   * @tparam TP2 second type_pack
   * @tparam Less metafunction predicate, which provides the member constant
   * `value` with the `bool` type, which is `true` if the first argument is less
   * than the second. The signature of this metafunction must be equivalent to
   * the following: `template <typename A, typename B> struct compare;`
   *
   * Checks if the first type_pack is lexicographically less than the second.
   * Elements are compared using binary comparsion metafunction `Less`. This
   * metafunction must provide the member constant `value` with the type `bool`,
   * which is true, if the first element is less the second.
   *
   * Lexicographical comparison is an operation with the following properties:
   *
   * - Two ranges are compared element by element.
   * - The first mismatching element defines which range is lexicographically
   * less or greater than the other.
   * - If one range is a prefix of another, the shorter
   * range is lexicographically less than the other.
   * - If two ranges have equivalent
   * elements and are of the same length, then the ranges are lexicographically
   * equal.
   * - An empty range is lexicographically less than any non-empty range. Two
   * empty ranges are lexicographically equal.
   */

  /**
   * @struct head
   * @brief Returns the first type of a type_pack
   *
   * @tparam T type_pack
   *
   * Provides the member typedef `type`, which is the first type of the
   * type_pack as a result. If type_pack is empty, `type` will be
   * `tp::empty_type`.
   *
   * Helper type
   *
   * @snippet type_pack.hpp headtimpl
   *
   * Implementation
   *
   * @snippet type_pack.hpp headimpl
   */

  /**
   * @struct at
   * @brief Performs access to elements of a type_pack by index
   *
   * @tparam Idx index
   * @tparam TP type_pack
   *
   * Provides the member typedef `type`, which is the element of a type_pack
   * with the index `Idx`. If an index is greater than size of a type_pack,
   * compiler error will happen.
   *
   * Helper type
   *
   * @snippet type_pack.hpp attimpl
   *
   * Implementation
   *
   * @snippet type_pack.hpp atimpl
   */

  /**
   * @struct max
   * @brief Returns the max type of a type_pack
   *
   * @tparam TP type_pack
   * @tparam Less metafunction predicate, which provides the member constant
   * `value` with the `bool` type, which is `true` if the first argument is less
   * than the second. The signature of this metafunction must be equivalent to
   * the following: `template <typename A, typename B> struct compare;`
   *
   * Provides the member typedef `type` with the "max" type from a type_pack.
   * If the type_pack is empty, the type will be `empty_type`.
   *
   * Helper type
   *
   * @snippet type_pack.hpp maxtimpl
   *
   * Implementation
   *
   * @snippet type_pack.hpp maximpl
   *
   * See sizeof_less, sizeof_more, base_is_less, derived_is_less.
   */

  /**
   * @struct min
   * @brief Returns the mintype of a type_pack
   *
   * @tparam TP type_pack
   * @tparam Less metafunction predicate, which provides the member constant
   * `value` with the `bool` type, which is `true` if the first argument is less
   * than the second. The signature of this metafunction must be equivalent to
   * the following: `template <typename A, typename B> struct compare;`
   *
   * Provides the member typedef `type` with the "min" type from a type_pack.
   * If the type_pack is empty, the type will be `empty_type`.
   *
   * Helper type
   *
   * @snippet type_pack.hpp mintimpl
   *
   * Implementation
   *
   * @snippet type_pack.hpp minimpl
   *
   * See sizeof_less, sizeof_more, base_is_less, derived_is_less.
   */

  /**
   * @struct contains
   * @brief Checks if the certain type exists in the type_pack
   *
   * @tparam T type
   * @tparam TP type_pack
   *
   * Provides the member constant `value` with the type `bool`, which is `true`
   * if the type is found in a pack and `false` otherwise.
   *
   * Implementation
   *
   * @snippet type_pack.hpp containsimpl
   */

  /**
   * @struct find
   * @brief Finds the certain type in the type_pack
   *
   * @tparam T type
   * @tparam TP type_pack
   * @tparam From start index (optional)
   *
   * Provides the member constant `value` with the type `std::size_t`, which is
   * an index of a type in a type_pack. If the type is not found, index will
   * be equal to the size of a type_pack.
   *
   * If `From` index is given, searching will started from it. By default this
   * index is 0.
   *
   * See find_if.
   */

  /**
   * @struct find_if
   * @brief First the first type in a type_pack satisfying predicate condition
   *
   * @tparam F unary predicate metafunction, that provides the member constant
   * `value` with the type `bool`. The signature must be equivalent to the
   * following: `template <typename T> struct pred;`
   * @tparam TP type_pack
   * @tparam From start index (optional)
   *
   * Provides the member constant `value` with the type `std::size_t`, which is
   * an index of a type in a type_pack. If the type is not found, index will
   * be equal to the size of a type_pack.
   *
   * If `From` index is given, searching will started from it. By default this
   * index is 0.
   *
   * See tp::find.
   */

  /**
   * @struct all_of
   * @brief Checks if unary predicate is `true` for all elements in a type_pack
   *
   * @tparam F unary predicate metafunction, that provides the member constant
   * `value` with the type `bool`. The signature must be equivalent to the
   * following: `template <typename T> struct pred;`
   * @tparam TP type_pack
   *
   * Provides the member constant `value` with the type `bool`, which is `true`
   * if unary predicate is `true` for all elements in a pack, `false` otherwise.
   * Inherits `std::integral_constant` members.
   *
   * Return value `true` if unary predicate returns true for all elements in the
   * range, `false` otherwise. Returns true if the range is empty.
   *
   * See tp::any_of, tp::none_of.
   */

  /**
   * @struct any_of
   * @brief Checks if unary predicate is `true` for at least one element in a
   * type_pack
   *
   * @tparam F unary predicate metafunction, that provides the member constant
   * `value` with the type `bool`. The signature must be equivalent to the
   * following: `template <typename T> struct pred;`
   * @tparam TP type_pack
   *
   * Provides the member constant `value` with the type `bool`, which is `true`
   * if unary predicate is `true` for at least one element in a pack, `false`
   * otherwise. Inherits `std::integral_constant` members.
   *
   * Return value `true` if unary predicate returns `true` for at least one
   * element in the range, `false` otherwise. Returns `false` if the range is
   * empty.
   *
   * See tp::all_of, tp::none_of.
   */

  /**
   * @struct none_of
   * @brief Checks if unary predicate is `true` for no elements in a type_pack
   *
   * @tparam F unary predicate metafunction, that provides the member constant
   * `value` with the type `bool`. The signature must be equivalent to the
   * following: `template <typename T> struct pred;`
   * @tparam TP type_pack
   *
   * Provides the member constant `value` with the type `bool`, which is `true`
   * if unary predicate is `true` for no elements in a pack, `false`
   * otherwise. Inherits `std::integral_constant` members.
   *
   * Return value `true` if unary predicate returns `true` for no elements in
   * the range, `false` otherwise. Returns `true` if the range is empty.
   *
   * Implementation
   *
   * @snippet type_pack.hpp NoneOfImpl
   *
   * See tp::any_of, tp::all_of.
   */

  /**
   * @struct count
   * @brief Returns the number of elements with the specific type
   *
   * @tparam T type to look for
   * @tparam TP type_pack
   *
   * Provides the member constant `value` with the type `std::size_t`. Counts
   * the elements that are equal to type `T` (using `std::is_same`).  Inherits
   * `std::integral_constant` members.
   *
   * If a pack is empty, result will be 0.
   *
   * See tp::count_if.
   */

  /**
   * @struct count_if
   * @brief Returns the number of elements satisfying predicate condition
   *
   * @tparam F unary predicate metafunction, that provides the member constant
   * `value` with the type `bool`. The signature must be equivalent to the
   * following: `template <typename T> struct pred;`
   * @tparam TP type_pack
   *
   * Provides the member constant `value` of type `std::size_t`. Counts elements
   * on which predicate returns `true`. Inherits `std::integral_constant`
   * members.
   *
   * If a pack is empty, result will be 0.
   *
   * See tp::count.
   */

  /**
   * @struct tail
   *
   * @brief Returns the type_pack which is a subrange of an original pack except
   * the first element
   *
   * @tparam TP type_pack
   *
   * Provides the member typedef `type` which is a type_pack of all elements of
   * an original pack except first element (head).
   *
   * If a pack is empty, result will be the same pack.
   *
   * See tp::head.
   */

  /**
   * @struct concatenate
   * @brief Concatenates type_packs and just_types
   *
   * Provides the member typedef `type` which is a pack of elements of
   * concatenation operands. If type of operands is just_type, then the
   * resulting type is type_pack with two elements. Allows to concatenate a
   * type_pack with just_type. If just_type is the first operand, its type
   * will be added to front of a pack, otherwise if just_type is the second
   * operand and type_pack is the first, type will be concatenated to back.
   *
   * Operation acts recursively and can concatenate more, that two operands.
   *
   * Note that `concatenate` requires type wrapped either in just_type or
   * type_pack. Attempt to concatenate type itself will cause a compiler error.
   *
   * See tp::push_back, tp::push_front.
   */

  /**
   * @struct copy
   * @brief Constructs new type_pack with the elements of other type_pack
   *
   * @tparam TP original type_pack
   * @tparam StartIdx begin
   * @tparam EndIdx end
   *
   * Provides the member typedef `type` that is a pack with elements of the
   * other type_pack on range [begin; end).
   *
   * In following cases compilation error will happen:
   * - If the begin index is greater than end index
   * - If the end index is greater than the size of a pack
   *
   * See tp::copy_if.
   */

} // namespace tp
