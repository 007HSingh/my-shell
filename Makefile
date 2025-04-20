CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lreadline
SOURCES = main.c input.c executor.c builtins.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = myshell

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c shell.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

install:
	install -m 755 $(TARGET) /usr/local/bin/

uninstall:
	rm -f /usr/local/bin/$(TARGET)

.PHONY: all clean install uninstall
