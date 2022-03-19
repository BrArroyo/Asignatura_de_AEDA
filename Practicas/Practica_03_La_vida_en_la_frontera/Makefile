# Makefile 

make:  include/grid.h include/grid_with_reflective_border.h include/grid_with_periodic_border.h include/grid_with_open_border.h include/cell.h include/state.h include/state_dead.h include/state_alive.h src/main.cc
	g++ -std=c++11 src/grid_with_reflective_border.cc src/grid_with_periodic_border.cc src/grid_with_open_border.cc src/cell.cc src/main.cc src/state_dead.cc src/state_alive.cc -o border_life -pthread

clean:
	rm -f .out border_life	