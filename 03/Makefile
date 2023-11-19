# compiler to use
CC = g++
CC_FLAGS=-std=c++20 -pedantic -Wsign-compare
CC_GTEST_FLAGS=-lgtest_main -lgtest -lpthread

.DEFAULT_GOAL := Task3.cpp
.PHONY: Task3.cpp  # чтобы убрать ошибку "is up to date.." (помечаем цель как фальшивую)

Task3.cpp:
	$(CC) -o Task3 Task3.cpp -lallocator -L./

lib:
	$(CC) -c allocator.cpp
	ar rc liballocator.a allocator.o

run:
	./Task3

test:
	$(CC) -o test_bin test.cpp -lallocator -L./ $(CC_GTEST_FLAGS)


clean:
	rm -f Task3 test_bin *.o *.a