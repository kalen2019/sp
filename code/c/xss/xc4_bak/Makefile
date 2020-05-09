CC := gcc
CFLAGS = -m32 -Wall -std=c99 -O0
# CFLAGS = -m32 -std=c99 -O0
TARGET = xcc xvm

all: $(TARGET)

xcc: xcc.c xvm.c # xobj.c 
	$(CC) $(CFLAGS) $^ -o $@

xvm: xvm.c xobj.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o $(TARGET)
