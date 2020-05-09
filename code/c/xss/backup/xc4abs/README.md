# xcc -- 將 C 語言編譯為堆疊機 xvm 的 elf 格式

xcc 修改自 jserv 的 amacc 專案！

* https://github.com/jserv/amacc

amacc 專案則是擴充自 c4 專案。

* https://github.com/rswier/c4

## 建置執行

```
PS D:\ccc\course\sp\code\c\xos\xcc> make xcc
gcc -std=c99 -O0 xcc.c xobj.c xvm.c -o xcc

PS D:\ccc\course\sp\code\c\xos\xcc> ./xcc -d test/hello.c
1> 0001:ENT  0
2> 0003:IMM  11010136
3> 0005:PSH
4> 0006:PRTF
hello, world
5> 0007:ADJ  1
6> 0009:IMM  0
7> 0011:LEV
8> 376830:PSH
9> 376831:EXIT
exit(0) cycle = 9
```
