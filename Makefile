gccc = g++ -Wall -Werror -Wextra

all: exec

exec:
	gcc *.cc -o test
	./test

clean:
	rm -rf ./test