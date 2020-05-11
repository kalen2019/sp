# 

mingw32 位元的 read 有問題

讀取 sum.o, fib.o 時，長度會有錯誤。

應該是 6xx 位元，讀到的卻只有 256 位元。

解決方式，沒有指定 binary, 改用 fread(..."rb") 就可以解決。

