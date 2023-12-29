# compiler to use
CC = g++
CC_FLAGS=-std=c++20 -pedantic -Wsign-compare
CC_GTEST_FLAGS=-lgtest_main -lgtest -lpthread

.DEFAULT_GOAL := Task6.cpp
.PHONY: Task6.cpp  # чтобы убрать ошибку "is up to date.." (помечаем цель как фальшивую)

Task6.cpp:
	$(CC) -o Task6 Task6.cpp -lbigint -L./

lib:
	$(CC) -c bigint.cpp
	ar rc libbigint.a bigint.o

run:
	./Task6

test:
	$(CC) -o test_bin test.cpp -lbigint -L./ $(CC_GTEST_FLAGS)

clean:
	rm -f Task6 test_bin *.o *.a