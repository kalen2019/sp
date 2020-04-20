# C4 -- 500 行的 C 語言編譯器 (修改版)

C in four functions

修改者 -- 陳鍾誠
作者 -- https://github.com/rswier/
來源 -- https://github.com/rswier/c4

* [原理說明](doc)

## 使用方式

An exercise in minimalism.

Try the following:

    gcc -o c4 c4.c  (you may need the -m32 option on 64bit machines)
    ./c4 hello.c
    ./c4 -s hello.c
    
    ./c4 c4.c hello.c
    ./c4 c4.c c4.c hello.c

