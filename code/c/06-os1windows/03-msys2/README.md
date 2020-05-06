# 安裝

* https://www.msys2.org/

## 安裝完之後

請開啟 MSYS2 64bits (不要用 MSYS2 32bits)

繼續安裝 gcc 之類的套件

```
$ pacman -S gcc
$ pacman -S vim
...
```

## 接著執行

```
user@DESKTOP-96FRN6B MINGW64 ~
$ cd /d/ccc/course/sp/code/c/06-os1windows/03-msys2

user@DESKTOP-96FRN6B MINGW64 /d/ccc/course/sp/code/c/06-os1windows/03-msys2
$ ls
georgeMary.c  README.md

user@DESKTOP-96FRN6B MINGW64 /d/ccc/course/sp/code/c/06-os1windows/03-msys2
$ gcc georgeMary.c -o georgeMary

user@DESKTOP-96FRN6B MINGW64 /d/ccc/course/sp/code/c/06-os1windows/03-msys2
$ ./georgeMary
George
----------------
Mary
George
----------------
George
----------------
Mary
----------------
George
George
Mary
----------------


```
