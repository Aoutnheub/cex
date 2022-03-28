A collection of small libraries.

## Build and install

```
git clone https://github.com/Aoutnheub/cex.git && cd cex
```

```
mkdir build && cd build
```

**Without tests**

```
cmake ..
```

**With tests**

```
cmake -D BUILD_TESTS=ON
```

```
cmake --build . --config Release
```

```
cmake --install . --config Release
```

## Current and future libraries

- [x] `args` : Command line argument parser
- [x] `color` : Colored terminal output
- [ ] `base64` : Base64 encoder/decoder
- [ ] `hash` : Hashing algorithms
- [ ] `html` : HTML parser
- [ ] `json` : JSON parser
- [x] `vector` : 2D/3D vectors
- [ ] `sort` : Sorting algorithms
- [ ] `uuid` : UUID generator
