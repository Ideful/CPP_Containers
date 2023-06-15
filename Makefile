gccc = g++ -Wall -Werror -Wextra 
FLAGS = -Wall -Werror -Wextra  -g 
SRC = list.tpp

all: exec

exec:
	g++  -Wall -Werror -Wextra -std=c++17 -g *.cc -o test_exec
	./test_exec

leaks:
	g++ -g -fsanitize=address *.cc -o test_exec
	./test_exec

test:
	g++ -std=c++17 $(FLAGS) list.tpp ContainerTest.cc -L.  -lgtest  -o test_exec
	./test_exec


clean:
	rm -rf ./test_exec ./test *.gcno ./test *.gcda