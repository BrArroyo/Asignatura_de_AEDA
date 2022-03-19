# Makefile 

make:  include/grid.h include/cell.h include/state.h include/state_dead.h include/state_alive.h src/main.cc
	g++ -std=c++11 src/grid.cc src/cell.cc src/main.cc src/state_dead.cc src/state_alive.cc -o border_life

clean:
	rm -f .out border_life	