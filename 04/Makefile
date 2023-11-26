# compiler to use
CC = g++
CC_FLAGS=-std=c++20 -pedantic -Wsign-compare
CC_GTEST_FLAGS=-lgtest_main -lgtest -lpthread

.DEFAULT_GOAL := Task4.cpp
.PHONY: Task4.cpp  # чтобы убрать ошибку "is up to date.." (помечаем цель как фальшивую)

Task4.cpp:
	$(CC) -o Task4 Task4.cpp -lparser -L./

lib:
	$(CC) -c parser.cpp
	ar rc libparser.a parser.o

run:
	./Task4

#test:
#	$(CC) -o test_bin test.cpp -lparser -L./ $(CC_GTEST_FLAGS)


clean:
	rm -f Task4 test_bin *.o *.a