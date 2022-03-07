/**
 * Archivo cell.h: Clase Cell.
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzados
 * Curso: 2º
 * Práctica 01: El juego de la vida 
 *
 * @author Bruno Lorenzo Arroyo Pedraza
 * @email alu0101123677@ull.edu.es
 * @date 01/03/2022
 * 
 * @brief Desarrollo de las funciones de la clase Cell 
 * 
 * La función de la clase Cell es 
 *  
 * Historial de versiones:
 *   01/03/2022 - Ver 0.1 Creación y primera versión del código
 */

#include "../include/cell.h"

Cell::Cell() {
  state_ = dead;
  live_neighbors_ = 0; 
}

Cell::~Cell() {

}

State Cell::GetState() const {
  return state_;
}


void Cell::SetState(State state) {
  state_ = state;  
}

void Cell::SetPosition(std::pair<int, int> position) {
  position_ = position;
}

std::pair<int, int> Cell::GetPosition() const {
  return position_;
}

/**
 * @brief 
 * 
 */
void Cell::UpdateState() {
  if (state_ == dead) {
    if (live_neighbors_ == 3) {
      state_ = live;
    } else {
      state_ = dead;
    }
  } else {
    if (live_neighbors_ == 2 || live_neighbors_ == 3) {
      state_ = live;  
    } else {
      state_ = dead;
    }
  }  
}

/**
 * @brief 
 * 
 * @return int 
 */
int Cell::Neighbors(const Grid& grid) {
  live_neighbors_ = 0;  

  /* Averiguar como funcionar con doble bucle
  for (int i = position_.first - 1; i <= position_.first + 1; i++) {
    for (int j = position_.second - 1; j <= position_.second + 1; j++) {
      if(i != position_.first && j != position_.second) {
        if (grid.GetCell(i, j).GetState() == live) {
          live_neighbors_++;
        }
      }
    }
  }*/   
  
  // i - 1, j - 1
  if(grid.GetCell(position_.first - 1, position_.second - 1).GetState() == live) {
    live_neighbors_++;
  }
  // i - 1, j
  if(grid.GetCell(position_.first - 1, position_.second).GetState() == live) {
    live_neighbors_++;
  }
  // i - 1, j + 1
  if(grid.GetCell(position_.first - 1, position_.second + 1).GetState() == live) {
    live_neighbors_++;
  }
  // i, j - 1
    if(grid.GetCell(position_.first, position_.second - 1).GetState() == live) {
    live_neighbors_++;
  }
  // i, j + 1  
  if(grid.GetCell(position_.first, position_.second + 1).GetState() == live) {
    live_neighbors_++;
  }
  // i + 1, j - 1  
  if(grid.GetCell(position_.first + 1, position_.second - 1).GetState() == live) {
    live_neighbors_++;
  }
  // i + 1, j  
  if(grid.GetCell(position_.first + 1, position_.second).GetState() == live) {
    live_neighbors_++;
  }
  // i + 1, j + 1  
  if(grid.GetCell(position_.first + 1, position_.second + 1).GetState() == live) {
    live_neighbors_++;
  }

  return live_neighbors_;
}

/**
 * @brief 
 * 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Cell& cell) {
  if (cell.GetState() == dead) {
    os << " ";
  } else {
    os << "x";
  }
  return os;
}