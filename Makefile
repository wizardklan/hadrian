.PHONY: tests clean

CC := clang
CFLAGS := -std=c99 \
          -Wall \
          -Wextra \
          -Wpedantic \
tests:
	$(CC) tests/iterator_test.c src/iterator/iterator.c -o tests/iterator_test.exe $(CFLAGS)

clean:
	rm -f *.exe
