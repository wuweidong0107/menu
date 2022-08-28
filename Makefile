TARGET=example/menu

SRC=example/menu.c \
src/shell.c \
src/mainloop.c \
src/io-mainloop.c \
src/util.c

all: ${TARGET}

example/menu: $(SRC)
	gcc  $^ -o $@

clean:
	rm -f $(TARGET)