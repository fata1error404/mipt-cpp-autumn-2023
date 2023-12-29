# compiler to use
CC = g++
CC_FLAGS=-std=c++20 -pedantic -Wsign-compare
CC_GTEST_FLAGS=-lgtest_main -lgtest -lpthread

.DEFAULT_GOAL := Task8.cpp
.PHONY: Task8.cpp  # чтобы убрать ошибку "is up to date.." (помечаем цель как фальшивую)

Task8.cpp:
	$(CC) -o Task8 Task8.cpp -lformat -L./

lib:
	$(CC) -c format.cpp
	ar rc libformat.a format.o

run:
	./Task8

test:
	$(CC) -o test_bin test.cpp -lformat -L./ $(CC_GTEST_FLAGS)

clean:
	rm -f Task8 test_bin *.o *.a