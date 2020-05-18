# glib

參考: https://www.ibm.com/developerworks/linux/tutorials/l-glib/index.html

```
guest@localhost:~/sp/code/c/10-os2linux/01-c/lib/02-glib$ make gslist
gcc gslist.c -o gslist `pkg-config --cflags glib-2.0` -g -Wall -std=gnu11 -O3 `pkg-config --libs glib-2.0`
guest@localhost:~/sp/code/c/10-os2linux/01-c/lib/02-glib$ ./gslist
a
b
c
```

## pkg-config

```
guest@localhost:~/sp/code/c/10-os2linux/01-c/lib/02-glib$ pkg-config --cflags glib-2.0
-I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include
guest@localhost:~/sp/code/c/10-os2linux/01-c/lib/02-glib$ pkg-config --libs glib-2.0
-lglib-2.0
```