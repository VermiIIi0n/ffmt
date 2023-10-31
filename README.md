# Fast Format++

## Intro

A simple and fast implementation for C++

Formatting into string is all it does.

## Usage

### Simple case

```cpp
ffmt::format("Hello, {}!", "world");  // Hello, world!
```

### Specify the index

```cpp
ffmt::format("Hello, {1}! {0}", "world", "Hello"); // Hello, world!
```

### Integer

```cpp
ffmt::format("Hello, {1:9}! {0}", 123, 456); // Hello,       456! 123
ffmt::format("{:*^9}", 123); // ***123***
ffmt::format("{:*^9x}", 0xfff); // ***fff***
ffmt::format("{:0^9x}", 0xfff); // '000fff   ' //trailing 0s will change the value, so they are replaced with ' '
ffmt::format("{:>+09}", 123); // +00000123 // '+'/'-' signs are moved to the left when fill char is '0'
```

### Float

```cpp
ffmt::format("{}", 1.234567); // 1.234567
ffmt::format("{:.e}", 123.456); // 1.234567e2 Force to scientific notation
ffmt::format("{:.2}", 1234567890987654321); // 1.23e+18
ffmt::format("{:.2f}", 1234567890987654321.0); // 1234567890987654321.00 Force to float
ffmt::format("{:<05}", 1.23); // 1.2300  // in this case, it's safe to append 0s
```

### General format string syntax

`"{[index]:[fill][align][sign][padding].[precision][format]}"`

* `index`: The index of the argument to format. It starts from `0`.
* `sign`: `+` - Always show sign, `-` - no sign for non-negative(default).
* `align`:
  * `>` - Right align(default)
  * `<` - Left align
  * `^` - Center align.
* `fill`: The fill character. Default is space.
  * Anything not an `Align` symbol
  * nor a `Sign` symbol
  * nor `.`
  * nor `int`(except `0`, `0` can be put before align or padding, output string will not affect the numeric value of the argument), `format` identifier may be used.
* `padding`: String at least takes this much space. Default is `0`.
* `precision`: The precision of the argument. Default is `6`.
* `format`: **To specify format only, use `{:.[format]}` instead of `{:[format]}` or `{[format]}`, in `{:f}`, `'f'` will be treated as fill char**
  * `b` - Binary
  * `o` - Octal
  * `d` - Decimal
  * `x` - Hexadecimal
  * `e` - Scientific notation
  * `f` - Float
  * `p` - Pointer
  * default is decimal for `int`, auto for `float`(choose `f` or `e` based on length and padding settings).

*To escape `{`, use `"{{"`.*

### Benchmark

Versus `fmt::format`:

#### Pure string

```sh
------------------------------------------------------
Benchmark            Time             CPU   Iterations
------------------------------------------------------
ffmt_format        151 ns         87.6 ns      7854519
fmt_format         510 ns          298 ns      2352726
```

#### `int`

```sh
------------------------------------------------------
Benchmark            Time             CPU   Iterations
------------------------------------------------------
ffmt_format       1044 ns          444 ns      1675920
fmt_format        4192 ns         1703 ns       394154
```

#### `float`

```sh
------------------------------------------------------
Benchmark            Time             CPU   Iterations
------------------------------------------------------
ffmt_format        387 ns          193 ns      2618041
fmt_format        1329 ns          551 ns      1271178
```
