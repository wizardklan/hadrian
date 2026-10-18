.PHONY: tests clean

CC := clang
CFLAGS := -std=c99 \
          -Wall \
          -Wextra \
          -Wpedantic
tests:
	$(CC) tests/iterator_test1.c src/iterator/iterator.c -o tests/iterator_test1.exe $(CFLAGS)
	$(CC) tests/carrays_static_test.c src/algorithms/carrays_static.c -o tests/carrays_static_test.exe $(CFLAGS)

clean:
	rm -f *.exe
