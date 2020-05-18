# glib

參考: https://www.ibm.com/developerworks/linux/tutorials/l-glib/index.html

```
guest@localhost:~/sp/code/c/10-os2linux/10-glib$ export CFLAGS="`pkg-config --cflags glib-2.0` -g -Wall -std=gnu11 -O3"
guest@localhost:~/sp/code/c/10-os2linux/10-glib$ export LDLIBS="`pkg-config --libs   glib-2.0`"
guest@localhost:~/sp/code/c/10-os2linux/10-glib$ make gslist
gcc gslist.c -o gslist -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -g -Wall -std=gnu11 -O3 -lglib-2.0
guest@localhost:~/sp/code/c/10-os2linux/10-glib$ ls
dict_test.c  gslist  gslist1.c  gslist.c  htable.c  Makefile  README.md
guest@localhost:~/sp/code/c/10-os2linux/10-glib$ ./gslist
a
b
c
```