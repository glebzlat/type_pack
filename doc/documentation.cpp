namespace tp {
  /**
   * @struct is_equal
   * @brief Checks if two type_packs or just_types equal
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
   * @brief Checks if type_packs or just_types not equal
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
   * @brief Lexicographically compares two type packs
   *
   * @tparam TP1 first type_pack
   * @tparam TP2 second type_pack
   * @tparam Less @ref comp_meta_req "comparsion metafunction"
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
   * @brief Returns the first type of a pack
   *
   * @tparam T type_pack
   *
   * Provides the member typedef `type`, which is the first type of the
   * type_pack as a result. If a pack is empty, member typedef will not be
   * provided, which may cause a compilation error.
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
   * @tparam Less @ref comp_meta_req "comparsion metafunction"
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
   * @tparam Less @ref comp_meta_req "comparsion metafunction"
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
   * Implementation
   *
   * @snippet type_pack.hpp findimpl
   *
   * See find_if.
   */

  /**
   * @struct find_if
   * @brief First the first type in a type_pack satisfying predicate condition
   *
   * @tparam F @ref unpred_req "unary_predicate"
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
   * Implementation
   *
   * @snippet type_pack.hpp findifimpl
   *
   * See tp::find.
   */

  /**
   * @struct all_of
   * @brief Checks if unary predicate is `true` for all elements in a type_pack
   *
   * @tparam F @ref unpred_req "unary_predicate"
   * @tparam TP type_pack
   *
   * Provides the member constant `value` with the type `bool`, which is `true`
   * if unary predicate is `true` for all elements in a pack, `false` otherwise.
   * Inherits `std::integral_constant` members.
   *
   * Return value `true` if unary predicate returns true for all elements in the
   * range, `false` otherwise. Returns true if the range is empty.
   *
   * Implementation
   *
   * @snippet type_pack.hpp allofimpl
   *
   * See tp::any_of, tp::none_of.
   */

  /**
   * @struct any_of
   * @brief Checks if unary predicate is `true` for at least one element in a
   * type_pack
   *
   * @tparam F @ref unpred_req "unary_predicate"
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
   * Implementation
   *
   * @snippet type_pack.hpp anyofimpl
   *
   * See tp::all_of, tp::none_of.
   */

  /**
   * @struct none_of
   * @brief Checks if unary predicate is `true` for no elements in a type_pack
   *
   * @tparam F @ref unpred_req "unary_predicate"
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
   * @snippet type_pack.hpp noneofimpl
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
   * @snippet type_pack.hpp countimpl
   *
   * See tp::count_if.
   */

  /**
   * @struct count_if
   * @brief Returns the number of elements satisfying predicate condition
   *
   * @tparam F @ref unpred_req "unary predicate"
   * @tparam TP type_pack
   *
   * Provides the member constant `value` of type `std::size_t`. Counts elements
   * on which predicate returns `true`. Inherits `std::integral_constant`
   * members.
   *
   * If a pack is empty, result will be 0.
   *
   * Implementation
   *
   * @snippet type_pack.hpp countifimpl
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
   * an original pack except first element (head). If a pack is empty,
   * member typedef will not be provided, which may cause a compilation error.
   *
   * Helper type
   *
   * @snippet type_pack.hpp tailtimpl
   *
   * Implementation
   *
   * @snippet type_pack.hpp tailimpl
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
   * Helper type
   *
   * @snippet type_pack.hpp concatenatetimpl
   *
   * Implementation
   *
   * @snippet type_pack.hpp concatenateimpl
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
   * Helper type
   *
   * @snippet type_pack.hpp copytype
   *
   * Implementation
   *
   * @snippet type_pack.hpp copyimpl
   *
   * See tp::copy_if.
   */

  /**
   * @struct copy_if
   * @brief Constructs new type_pack with the elements, that satisfying a
   * condition, of other type_pack
   *
   * @tparam TP type_pack
   * @tparam F @ref unpred_req "unary predicate"
   *
   * Provides the member typedef `type` that is a pack with elements of other
   * type_pack. Algorithm copies elements, for which unary predicate returns
   * `true`.
   *
   * Helper type
   *
   * @snippet type_pack.hpp copyiftype
   *
   * Implementation
   *
   * @snippet type_pack.hpp copyifimpl
   *
   * See tp::copy.
   */

  /**
   * @struct push_front
   * @brief Generates new type_pack by adding a type to the front of other
   * type_pack
   *
   * @tparam T adding type
   * @tparam TP type_pack
   *
   * Provides the member typedef `type` that is a pack with all elements of
   * other type_pack, prepended with added type.
   *
   * Helper type
   *
   * @snippet type_pack.hpp pushfronttype
   *
   * Implementation
   *
   * @snippet type_pack.hpp pushfrontimpl
   */

  /**
   * @struct push_back
   * @brief Generates new type_pack by adding a type to the back of other
   * type_pack
   *
   * @tparam T adding type
   * @tparam TP type_pack
   *
   * Provides the member typedef `type` that is a pack with all elements of
   * other type_pack, appended with added type.
   *
   * Helper type
   *
   * @snippet type_pack.hpp pushbacktype
   *
   * Implementation
   *
   * @snippet type_pack.hpp pushbackimpl
   */

  /**
   * @struct pop_front
   * @brief Removes the first type from a type_pack
   *
   * @tparam TP type_pack
   *
   * Provides the member typedef `type` that is a pack with all elements of
   * other type_pack, except the first element. If the original pack is empty,
   * resulting type is empty_pack.
   *
   * Helper type
   *
   * @snippet type_pack.hpp popfronttype
   *
   * Implementation
   *
   * @snippet type_pack.hpp popfrontimpl
   */

  /**
   * @struct pop_back
   * @brief Removes the last type from a type_pack
   *
   * @tparam TP type_pack
   *
   * Provides the member typedef `type` that is a pack with all elements of
   * other type_pack, except the last element. If the original pack is empty,
   * resulting type is empty_pack.
   *
   * Helper type
   *
   * @snippet type_pack.hpp popbacktype
   *
   * Implementation
   *
   * @snippet type_pack.hpp popbackimpl
   */

  /**
   * @struct transform
   * @brief Generates new type_pack from other type_pack by applying to its
   * elements transforming metafunction
   *
   * @tparam F unary transforming metafunction, that is take one template type
   * and provide the member typedef `type`. The signature of transforming
   * metafunction must be equivalent to the following: `template <typename T>
   * struct trans;`.
   *
   * @tparam TP type_pack
   *
   * Provides the member typedef `type` that is a type_pack, filled with types,
   * generated by transforming metafunction.
   *
   * Helper type
   *
   * @snippet type_pack.hpp transformtype
   *
   * Implementation
   *
   * @snippet type_pack.hpp transformimpl
   */

  /**
   * @struct generate
   * @brief Creates a type_pack with count of elements of a specific type
   *
   * @tparam N number of elements
   * @tparam T type of an element
   *
   * Provides the member typedef `type` that is a type_pack with N elements of
   * a type T. If N is 0, the resulting type is empty_pack.
   *
   * Helper type
   *
   * @snippet type_pack.hpp generatetype
   *
   * Implementation
   *
   * @snippet type_pack.hpp generateimpl
   */

  /**
   * @struct remove
   * @brief Removes the first element of a specific type
   *
   * @tparam T type to remove
   *
   * Provides the member typedef `type` that is a type_pack with elements from
   * the original type_pack except the first occurency of a type T.
   *
   * If a pack is empty, the resulting type is empty_pack.
   *
   * Helper type
   *
   * @snippet type_pack.hpp removetype
   *
   * Implementation
   *
   * @snippet type_pack.hpp removeimpl
   *
   * See remove_if.
   */

  /**
   * @struct remove_if
   * @brief Removes the first element, that satisfies a specific criteria
   *
   * @tparam F @ref unpred_req "unary predicate"
   *
   * Provides the member typedef `type` that is a type_pack with elements from
   * the original type_pack except the first occurency of a type, for which
   * unary predicate returned `true`.
   *
   * If a pack is empty, the resulting type is empty_pack.
   *
   * Helper type
   *
   * @snippet type_pack.hpp removeiftype
   *
   * Implementation
   *
   * @snippet type_pack.hpp removeifimpl
   */

  /**
   * @struct remove_all
   * @brief Removes all elements of a specific type
   *
   * @tparam T removing type
   *
   * Provides the member typedef `type` that is a type_pack with all elements
   * from the original type_pack except all elements of a type T.
   *
   * If a pack is empty, the resulting type is empty_pack.
   *
   * Helper type
   *
   * @snippet type_pack.hpp removealltype
   *
   * Implementation
   *
   * @snippet type_pack.hpp removeallimpl
   */

  /**
   * @struct remove_all_if
   * @brief Removes all elements, that satisfies a specific criteria
   *
   * @tparam F @ref unpred_req "unary predicate"
   *
   * Provides the member typedef `type` that is a type_pack with all elements
   * from the original type_pack except all elements for which predicate returns
   * `true`.
   *
   * Helper type
   *
   * @snippet type_pack.hpp removealliftype
   *
   * Implementation
   *
   * @snippet type_pack.hpp removeallieimpl
   */

  /**
   * @struct unique
   * @brief Removes duplicate types
   *
   * @tparam TP type_pack
   *
   * Eliminates all except the first element from every consecutive group of
   * equivalent elements from a type_pack. Provides the member typedef `type`.
   *
   * Helper type
   *
   * @snippet type_pack.hpp uniquetype
   *
   * Implementation
   *
   * @snippet type_pack.hpp uniqueimpl
   */

  /**
   * @struct replace
   * @brief Replaces all elements of a specific type
   *
   * @tparam Old old type to replace
   * @tparam New the type to use as replacement
   *
   * Replaces all elements of type Old to type New.
   *
   * Helper type
   *
   * @snippet type_pack.hpp replacetype
   *
   * Implementation
   *
   * @snippet type_pack.hpp replaceimpl
   */

  /**
   * @struct sort
   * @brief Sorts type_pack
   *
   * @tparam TP type_pack
   * @tparam Less @ref comp_meta_req "comparsion metafunction"
   *
   * Sorts list of types using comparsion metafunction. Provides the member
   * typedef `type` which is a pack of types, sorted in ascending order.
   *
   * Helper type
   *
   * @snippet type_pack.hpp sorttype
   *
   * Implementation
   *
   * @snippet type_pack.hpp sortimpl
   */

  /**
   * @page unary_predicate_struct Unary predicate struct
   *
   * @anchor unpred_req Unary predicate class is a metafunction that must
   * take one template parameter and provide the public member constant `value`
   * of type `bool`. The value of a member depends if a template parameter type
   * satisfies or not the predicate's criteria.
   *
   * The C++ standard library offers a great set of unary predicates, which are
   * called "type categories" and "type properties". See
   * https://en.cppreference.com/w/cpp/header/type_traits
   *
   * Unary predicate definition may follow SFINAE principle. It is strongly
   * recommended to inherit unary_predicate classes from std::integral_constant.
   *
   * Example:
   *
   * ```cpp
   * template <typename T>
   * struct is_int : std::false_type {};
   *
   * template <>
   * struct is_int<int> : std::true_type {};
   * ```
   *
   * See copy_if, remove_if, count_if, tp::all_of, tp::any_of, tp::none_of.
   */

  /**
   * @page comparsion_meta Metafunctions that provide comparsion operations
   *
   * @anchor comp_meta_req Comparsion metafunction is a class, that takes
   * two template parameters and provides the public member constant `value`
   * of type `bool`. The value of a member depends if one type is "greater" or
   * "less" than other.
   *
   * Comparsion between types actually is not a comparsion in the usual sense.
   * Types are quite abstract category to define a comparsion operation for
   * them.
   *
   * But in the computer representation all types has their size, which is a
   * material trait of a type. So types can be compared by their sizes.
   *
   * @snippet type_pack.hpp sizeof_compare
   *
   * Also types can be classes, which has the inheritance relationship. You can
   * say that is a derived class is "lesser" than the base class.
   *
   * @snippet type_pack.hpp baseis_compare
   *
   * It is strongly recommended to inherit comparsion classes from
   * `std::integral_constant` class. User can easily define its own comparsion
   * metafunction by using metaprogramming logical operations, that are
   * provided by the library.
   *
   * @snippet type_pack.hpp logicalimpl
   *
   * See sizeof_less, sizeof_more, base_is_less, derived_is_less, tp::negation,
   * tp::conjunction, tp::disjunction.
   *
   */

} // namespace tp
