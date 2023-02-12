# type_pack

[![gcc](https://github.com/edKotinsky/type_pack/actions/workflows/gcc.yml/badge.svg)](https://github.com/edKotinsky/type_pack/actions/workflows/gcc.yml)
[![clang](https://github.com/edKotinsky/type_pack/actions/workflows/clang.yml/badge.svg)](https://github.com/edKotinsky/type_pack/actions/workflows/clang.yml)

My type list implementation using template parameter packs. Written in pure
C++11.

Almost completely tested. Documentation is in progress.

## Features

Currently library provides the following operations. List may be incomplete,
for all features and for the detailed description see the documentation.

There are three main groups of operations:

Element accessing operations, that return one specific type from a type_pack
by index or by its position. These operations provide a member typedef `type`
as a result.

Indexing operations provide a constant member `value` as a result. They are
divided into following categories:
- Operations that check if a type exists in a type_pack. These are: `all_of`,
`any_of`, `none_of`, `contains`. Result type is bool.
- Operations that return an index of a type if this type exists in a type_pack.
These are: `find`, `find_if`. Result type is `size_t`.
- Operations that return count of specific types or types, on which a
predicate returns true: `count`, `count_if`. Result type is `size_t`.

Generation operations, which generate new type_pack from the other type_pack,
or create new type_pack from the other data (e.g. `generate` creates a type_pack
with N elements of a specific type). Some of these operations generate new
pack from the other, conditionally, by index or by position. Generation
operations provide member typedef `type`, which is a type_pack with some types
(or empty_pack in some cases) as a result.

_Element accessing operations_
- head
- at

_Indexing operations_
- contains
- find
- find_if
- all_of
- any_of
- none_of
- count
- count_if

_Generation operations_
- copy
- copy_if
- tail
- concatenate
- push_front
- push_back
- pop_front
- pop_back
- transform
- generate
- remove
- remove_if
- remove_all
- remove_all_if
- unique
- replace

## Installation

```sh
git clone https://github.com/edKotinsky/type_pack.git
cmake -S . -B build
cmake --build build
```

## Testing

```sh
cmake -S . -B build -D TYPE_PACK_TESTING=ON
cmake --build build
```

## Documentation

```sh
cmake -S . -B build -D TYPE_PACK_DOC=ON
cmake --build build
```

## License

[Licensed under MIT License](./LICENSE)
