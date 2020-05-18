# packages

```
PS D:\ccc\course\rust\02-packages\01-hello-packages> cargo new usepackage1
     Created binary (application) `usepackage1` package
PS D:\ccc\course\rust\02-packages\01-hello-packages>  ^C===>           ] 62/76: clap, regex, globset, syn
PS D:\ccc\course\rust\02-packages\01-hello-packages\usepackage1> cargo build
   Compiling usepackage1 v0.1.0 (D:\ccc\course\rust\02-packages\01-hello-packages\usepackage1)
  --> src\main.rs:15:26
   |
15 |     println!("nums: {}", nums);
   |                          ^^^^ `std::vec::Vec<i32>` cannot be formatted with the default formatter
   |
   = help: the trait `std::fmt::Display` is not implemented for `std::vec::Vec<i32>`
   = note: in format strings you may be able to use `{:?}` (or {:#?} for pretty-print) instead
   = note: required by `std::fmt::Display::fmt`
   = note: this error originates in a macro (in Nightly builds, run with -Z macro-backtrace for more info)


For more information about this error, try `rustc --explain E0277`.
error: could not compile `usepackage1`.

To learn more, run the command again with --verbose.
PS D:\ccc\course\rust\02-packages\01-hello-packages\usepackage1> cargo build
   Compiling usepackage1 v0.1.0 (D:\ccc\course\rust\02-packages\01-hello-packages\usepackage1)
warning: unused variable: `y`
  --> src\main.rs:11:9
   |
11 |     let y: f64 = rng.gen(); // generates a float between 0 and 1
   |         ^ help: consider prefixing with an underscore: `_y`
   |
   = note: `#[warn(unused_variables)]` on by default

    Finished dev [unoptimized + debuginfo] target(s) in 3.41s
PS D:\ccc\course\rust\02-packages\01-hello-packages\usepackage1> ./target/debug/usepackage1
Hello, world!
nums: [96, 48, 10, 23, 42, 5, 44, 36, 39, 65, 90, 15, 56, 86, 61, 32, 9, 4, 21, 50, 81, 30, 87, 17, 51, 7, 80, 35, 45, 2, 57, 69, 33, 11, 14, 71, 76, 12, 18, 92, 77, 29, 16, 84, 34, 49, 40, 79, 53, 58, 82, 70, 94, 74, 98, 55, 64, 89, 31, 59, 38, 67, 8, 1, 73, 46, 62, 83, 26, 78, 27, 25, 85, 91, 3, 72, 95, 66, 19, 75, 60, 99, 22, 41, 6, 13, 43, 52, 68, 
37, 24, 93, 28, 47, 54, 97, 88, 20, 63]
```
