CC := gcc
CFLAGS = -std=c99 -O0
TARGET = xcc xvm

all: $(TARGET)

xcc: xcc.c xobj.c xvm.c
	$(CC) $(CFLAGS) $^ -o $@

xvm: xvm.c xobj.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o *.exe
