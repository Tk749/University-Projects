all: clear clean compile run

compile: main.cpp 
	@g++ -c gates.cpp
	@g++ main.cpp -std=c++11 gates.cpp -o output

run:

	./output


clean:
	@rm -f *.o
	@rm -f output
	
clear: