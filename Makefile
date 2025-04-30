CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99 -D_POSIX_C_SOURCE=200809L
CFLAGS_DEBUG = -Wall -Wextra -pedantic -std=c99 -D_POSIX_C_SOURCE=200809L -g3 -O0
SRCDIR = ./src
BINDIR = ./bin

SRCFILES = $(wildcard $(SRCDIR)/*.c)

OBJS = $(patsubst $(SRCDIR)/%.c, $(BINDIR)/%.o, $(SRCFILES))
OBJS_DEBUG = $(patsubst $(SRCDIR)/%.c, $(BINDIR)/%_debug.o, $(SRCFILES))

TARGET = $(BINDIR)/ht
TARGET_DEBUG = $(BINDIR)/ht_debug

run: $(BINDIR) $(TARGET)
	$(TARGET)

debug: $(BINDIR) $(TARGET_DEBUG)
	gdb -q $(TARGET_DEBUG)

$(BINDIR):
	mkdir -p $(BINDIR)

$(BINDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(BINDIR)/%_debug.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS_DEBUG) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -lm -o $(TARGET) $(OBJS)

$(TARGET_DEBUG): $(OBJS_DEBUG)
	$(CC) $(CFLAGS_DEBUG) -lm -o $(TARGET_DEBUG) $(OBJS_DEBUG)

.PHONY: all clean run debug

all: $(TARGET)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_DEBUG)
	rm -f $(TARGET)
	rm -f $(TARGET_DEBUG)
	rmdir $(BINDIR)
