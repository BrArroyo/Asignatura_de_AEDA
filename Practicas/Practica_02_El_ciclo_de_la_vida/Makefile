# Makefile 

make:  include/grid.h include/cell.h include/state.h include/state_dead.h include/state_egg.h include/state_larva.h include/state_pupa.h include/state_adult.h src/main.cc
	g++ -std=c++11 src/grid.cc src/cell.cc src/main.cc src/state_dead.cc src/state_egg.cc src/state_larva.cc src/state_pupa.cc src/state_adult.cc -o life_cycle

clean:
	rm -f .out life_cycle