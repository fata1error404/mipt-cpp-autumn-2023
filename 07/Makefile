# compiler to use
CC = g++
CC_FLAGS=-std=c++20 -pedantic -Wsign-compare
CC_GTEST_FLAGS=-lgtest_main -lgtest -lpthread

.DEFAULT_GOAL := Task7.cpp
.PHONY: Task7.cpp  # чтобы убрать ошибку "is up to date.." (помечаем цель как фальшивую)

Task7.cpp:
	$(CC) -o Task7 Task7.cpp -lvector -L./

lib:
	$(CC) -c vector.cpp
	ar rc libvector.a vector.o

run:
	./Task7

test:
	$(CC) -o test_bin test.cpp -lvector -L./ $(CC_GTEST_FLAGS)

clean:
	rm -f Task7 test_bin *.o *.a