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
 * These operations perform element access, and declare the type member `type`
 * as the result. The result of these operations is either a type itself or a
 * type in a just_type wrapper.
 */

/**
 * @defgroup TypePackIndexing Type pack indexing operations
 * @ingroup TypePack
 *
 * @brief Operations that return indexes of types
 *
 * These operations provide the member constant value that can be an index of
 * the type in a type pack, the fact, is the partucular type in the pack or not,
 * or a count of types.
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
 * These operations create type_packs and declare the type member `type` as
 * the result. The result of these operations is a type_pack, which can be
 * a part of the original pack or a new pack.
 *
 * E.g. operations that remove some types from the original type_pack or
 * adds new.
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


