# compiler to use
CC = g++
CC_FLAGS=-std=c++20 -pedantic -Wsign-compare
CC_GTEST_FLAGS=-lgtest_main -lgtest -lpthread

.DEFAULT_GOAL := Task5.cpp
.PHONY: Task5.cpp  # чтобы убрать ошибку "is up to date.." (помечаем цель как фальшивую)

Task5.cpp:
	$(CC) -o Task5 Task5.cpp

run:
	./Task5

clean:
	rm -f Task5 *.o *.a