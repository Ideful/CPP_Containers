gccc = g++ -Wall -Werror -Wextra -Wall -Werror -Wextra
FLAGS = -Wall -Werror -Wextra -O0 -g 
SRC = list.tpp

all: exec

exec:
	g++  -Wall -Werror -Wextra -std=c++17 -g *.cc -lgtest_main  -lgtest -lpthread -o test_exec
	./test_exec

leaks:
	g++ -g -fsanitize=address *.cc -o test_exec
	./test_exec

test:
	g++ -std=c++17 $(FLAGS) $(SRC) ContainerTest.cc -L.   -lgtest  --coverage -o test
	./test


clean:
	rm -rf ./test_exec ./test *.gcno