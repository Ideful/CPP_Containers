gccc = g++ -Wall -Werror -Wextra

all: exec

exec:
	g++ -g *.cc -o test_exec
	./test_exec

leaks:
	g++ -g -fsanitize=address *.cc -o test_exec
	./test_exec



clean:
	rm -rf ./test_exec