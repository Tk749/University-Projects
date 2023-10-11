all: clear clean compile run

compile: main.cpp 
	@g++ -c Robot.cpp
	@g++ -c Roomba.cpp
	@g++ -c Bulldozer.cpp
	@g++ -c Robocop.cpp
	@g++ -c Humanic.cpp
	@g++ -c Optimusprime.cpp
	@g++ main.cpp -std=c++11 Optimusprime.cpp Humanic.cpp Robocop.cpp Bulldozer.cpp Roomba.cpp Robot.cpp -o output

run:

	./output

clean:
	@rm -f *.o
	@rm -f output
	
clear: