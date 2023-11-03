# compiler to use
CC = g++
CC_FLAGS=-std=c++20 -pedantic -Wsign-compare
CC_GTEST_FLAGS=-lgtest_main -lgtest -lpthread

.DEFAULT_GOAL := Task2.cpp
.PHONY: Task2.cpp  # чтобы убрать ошибку "is up to date.." (помечаем цель как фальшивую)

Task2.cpp:
	g++ -o Task2 Task2.cpp -lstemmer -L./

lib:
	g++ -c stemmer.cpp
	ar rc libstemmer.a stemmer.o

run:
	Task2

test:
	$(CC) -o test_bin test.cpp -lstemmer -L./ $(CC_GTEST_FLAGS)


clean:
	rm -f Task2 test_bin *.o *.a