# LLVM use

目前我安裝的版本是 clang-10 lldb-10 lld-10

## 使用




## 包含套件

```
Install
(stable branch)
To retrieve the archive signature:
wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key|sudo apt-key add -
# Fingerprint: 6084 F3CF 814B 57C1 CF12 EFD5 15CF 4D18 AF4F 7421


To install just clang, lld and lldb (10 release):
apt-get install clang-10 lldb-10 lld-10


To install all key packages:
# LLVM
apt-get install libllvm-10-ocaml-dev libllvm10 llvm-10 llvm-10-dev llvm-10-doc llvm-10-examples llvm-10-runtime
# Clang and co
apt-get install clang-10 clang-tools-10 clang-10-doc libclang-common-10-dev libclang-10-dev libclang1-10 clang-format-10 python-clang-10 clangd-10
# libfuzzer
apt-get install libfuzzer-10-dev
# lldb
apt-get install lldb-10
# lld (linker)
apt-get install lld-10
# libc++
apt-get install libc++-10-dev libc++abi-10-dev
# OpenMP
apt-get install libomp-10-dev
```
