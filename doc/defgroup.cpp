/**
 * @defgroup TypePack Type pack
 *
 * @brief A C++11 type list implementation
 *
 * Type pack is a list of types, stored in a template parameter pack.
 * Instead of a classic type list, which has head type and recursive tail,
 * type pack has not. Because template parameter packs was presented
 * in 11 C++ standard, type_pack requires C++11 or greater.
 */

/**
 * @defgroup TypePackElementAccess Element accessing operations
 * @ingroup TypePack
 *
 * @brief Type pack element accessing operations
 *
 * Element accessing operations, that return one specific type from a type_pack
 * by index or by its position. These operations provide a member typedef `type`
 * as a result.
 */

/**
 * @defgroup TypePackIndexing Type pack indexing operations
 * @ingroup TypePack
 *
 * @brief Operations that return indexes of types
 *
 * Indexing operations, which divides into following categories:
 * - Operations that check if a type exists in a type_pack. These are: all_of,
 * any_of, none_of, contains.
 * - Operations that return an index of a type if this type exists in a
 * type_pack. These are: find, find_if.
 * - Operations that return count of specific types or types, on which a
 * predicate returns true: count, count_if.
 * Indexing operations provide a constant member `value` as a result.
 */

/**
 * @defgroup TypePackRelationOps Relation operations
 * @ingroup TypePack
 *
 * @brief Type pack relation operations
 *
 * These operations perform comparsion between type_packs and just_types and
 * provide the member constant value that is `true` if packs and just_types
 * are equal and `false` otherwise. In case if these operations are functions,
 * they return bool result.
 */

/**
 * @defgroup TypePackGenerating Type pack generation operations
 * @ingroup TypePack
 *
 * @brief Operations that create a new type_pack
 *
 * Generation operations, what generate new type_pack from the other type_pack,
 * or create new type_pack from the other data (e.g. `generate` creates a
 * type_pack with N elements of a specific type). Some of these operations
 * generate new pack from the other, conditionally, by index or by position.
 * Generation operations provide member typedef `type`, which is a type_pack
 * with some types (or empty_pack in some cases) as a result.
 */

/**
 * @defgroup TypePackUtility Utilities
 * @ingroup TypePack
 *
 * @brief Utilities, that are useful with the other type_pack operations
 *
 * Utilities allow to apply third party metafunctions with the type_pack
 * operations.
 *
 * E.g. part_caller allows to apply metafunctions, which takes
 * two or more template parameters, in case when metafunction with one
 * template parameter is needed - "partially specialize" it.
 */

/**
 * @defgroup TypePackComparsion Comparsion operators
 * @ingroup TypePack
 *
 * @brief Operations that perform comparsion between types
 */
