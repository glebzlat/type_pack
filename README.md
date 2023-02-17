# type_pack

[![gcc](https://github.com/edKotinsky/type_pack/actions/workflows/gcc.yml/badge.svg)](https://github.com/edKotinsky/type_pack/actions/workflows/gcc.yml)
[![clang](https://github.com/edKotinsky/type_pack/actions/workflows/clang.yml/badge.svg)](https://github.com/edKotinsky/type_pack/actions/workflows/clang.yml)
[![Docs](https://github.com/edKotinsky/type_pack/actions/workflows/docs.yml/badge.svg)](https://github.com/edKotinsky/type_pack/actions/workflows/docs.yml)

This is my hobby project, that I have started because I wished to deeply explore
C++ metaprogramming. I have implemented a lot of great metaprogramming stuff,
which actually may seem as a "black magic". 

Here you can see such algorithms as lexicographic comparsion, generation,
conditional removing and even sorting. And it all is performed at compile-time 
with _types_, not material values. And it all is implemented using pure C++ 11 
standard.

You can read the 
[documentation of a project](https://edkotinsky.github.io/type_pack/), 
almost all features are documented.

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
