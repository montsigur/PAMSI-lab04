pomiar: main.cpp timer/src/Timer.cpp kopiec.cpp
	g++ -Wall -std=c++11 main.cpp kopiec.cpp timer/src/Timer.cpp

clean:
	rm -f pomiar
