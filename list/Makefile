gccc = g++ -Wall -Werror -Wextra 
FLAGS = -Wall -Werror -Wextra  -g 
SRC = list.tpp
GCOV= -fprofile-arcs -ftest-coverage

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
	rm -rf ./test_exec ./test *.gcno ./test *.gcda *.info gcov_report gcov_report.dSYM

gcov_report: clean
	g++ -std=c++17 $(FLAGS) --coverage *.cc -o gcov_report -lgtest -lstdc++
	./gcov_report
	geninfo --ignore-errors mismatch ContainerTest.gcda
	lcov -t "test" -o unit_test.info -c -d .
	genhtml -o report unit_test.info
	open ./report/index.html