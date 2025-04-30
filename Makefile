CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99

bin:
	mkdir -p ./bin

%: ./src/%.c bin
	$(CC) $(CFLAGS) -o $@ $<
	bin/$*

.PHONY: clean

clean:
	rm -f ./bin/main
