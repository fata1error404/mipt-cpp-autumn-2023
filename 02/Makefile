# compiler to use
CC = g++
CC_FLAGS=-std=c++20 -pedantic -Wsign-compare
CC_GTEST_FLAGS=-lgtest_main -lgtest -lpthread

.DEFAULT_GOAL := Task2.cpp
.PHONY: Task2.cpp  # чтобы убрать ошибку "is up to date.." (помечаем цель как фальшивую)

Task2.cpp:
	g++	-o Task2 Task2.cpp

run:
	Task2.exe

test:
	Task2.exe

clean:
	del -f *.exe
# почему rm не работает?