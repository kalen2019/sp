CC := gcc
TARGET = gslist

all: $(TARGET)

$(TARGET): gslist.c
	$(CC) $^ -o $@ $(CFLAGS) $(LDLIBS) 

clean:
	rm -f *.o *.exe
