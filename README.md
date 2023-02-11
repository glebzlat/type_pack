# type_pack

[![gcc](https://github.com/edKotinsky/type_pack/actions/workflows/gcc.yml/badge.svg)](https://github.com/edKotinsky/type_pack/actions/workflows/gcc.yml)
[![clang](https://github.com/edKotinsky/type_pack/actions/workflows/clang.yml/badge.svg)](https://github.com/edKotinsky/type_pack/actions/workflows/clang.yml)

My type list implementation using template parameter packs. Written in pure
C++11.

Almost completely tested. Documentation is in progress.

## Features

Currently library provides the following operations. List may be incomplete,
for all features see the documentation.

- _Element accessing operations_
	- `head`
	- `at`
- _Indexing operations._
	- `sub`
	- `contains`
	- `find`
	- `find_if`
	- `all_of`
	- `any_of`
	- `none_of`
	- `count`
	- `count_if`
- _Generation operations_
	- `sub`
	- `tail`
	- `concatenate`
	- `push_front`
	- `push_back`
	- `pop_front`
	- `pop_back`
	- `transform`
	- `generate`
	- `remove`
	- `remove_if`
	- `remove_all`
	- `remove_all_if`
	- `unique`
	- `replace`

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
