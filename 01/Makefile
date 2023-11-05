# compiler to use
CC = g++
CC_FLAGS=-std=c++20 -pedantic -Wsign-compare
CC_GTEST_FLAGS=-lgtest_main -lgtest -lpthread

.DEFAULT_GOAL := Task1.cpp
.PHONY: Task1.cpp  # чтобы убрать ошибку "is up to date.." (помечаем цель как фальшивую)

Task1.cpp:
	g++	-o Task1 Task1.cpp $(CC_GTEST_FLAGS)

run:
	Task1

test:
	g++	-o test_bin Task1.cpp $(CC_GTEST_FLAGS)

clean:
	rm -f Task1 test_bin
