# compiler to use
CC = g++
CC_FLAGS=-std=c++20 -pedantic -Wsign-compare
CC_GTEST_FLAGS=-lgtest_main -lgtest -lpthread

.DEFAULT_GOAL := Task9.cpp
.PHONY: Task9.cpp  # чтобы убрать ошибку "is up to date.." (помечаем цель как фальшивую)

Task8.cpp:
	$(CC) -o Task9 Task9.cpp -lbst -L./

lib:
	$(CC) -c bst.cpp
	ar rc libbst.a bst.o

run:
	./Task9

test:
	$(CC) -o test_bin test.cpp -lbst -L./ $(CC_GTEST_FLAGS)

clean:
	rm -f Task9 test_bin *.o *.a