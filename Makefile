CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99 -D_POSIX_C_SOURCE=200809L
SRCDIR = ./src
BINDIR = ./bin

SRCFILES = $(wildcard $(SRCDIR)/*.c)

OBJS = $(patsubst $(SRCDIR)/%.c, $(BINDIR)/%.o, $(SRCFILES))

TARGET = $(BINDIR)/ht

run: $(BINDIR) $(TARGET)
	$(TARGET)

$(BINDIR):
	mkdir -p $(BINDIR)

$(BINDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -lm -o $(TARGET) $(OBJS)

.PHONY: all clean run

all: $(TARGET)

clean:
	rm -f $(OBJS)
	rm -f $(TARGET)
	rmdir $(BINDIR)
