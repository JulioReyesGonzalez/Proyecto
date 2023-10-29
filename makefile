

bin/CrazyTaxi : src/CrazyTaxi.cpp include/*.hpp
	c++ src/CrazyTaxi.cpp -I include -o bin/CrazyTaxi -lcurses

run : bin/CrazyTaxi
	./bin/CrazyTaxi
