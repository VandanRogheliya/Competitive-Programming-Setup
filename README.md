## Setup

> Only for Mac

### Compiling
1. Use `gcc` compiler. Install using `brew install gcc`
2. Binary's name would be like: `g++-14`. Here `-14` is GCC version.

### LSP (NeoVim)
1. Use `clangd`
2. Ensure to point `compile_flags.txt` where GCC headers are stored.
3. If `bits/stdc++.h` header is not found then figure the path from where they are being read and copy GCC headers to that path.
