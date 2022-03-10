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
 * La función de la clase Cell es representar una célula para el juego
 * de la vida 
 *  
 * Historial de versiones:
 *   01/03/2022 - Ver 0.1 Creación y primera versión del código
 *   07/03/2022 - Ver 1.0 Versión terminada y comentada
 */

#include "../include/cell.h"

/**
 * @brief Construct a new Cell:: Cell object
 * 
 */
Cell::Cell() {
  state_ = dead;
  live_neighbors_ = 0; 
}

/**
 * @brief Destroy the Cell:: Cell object
 * 
 */
Cell::~Cell() {

}

/**
 * @brief Getter de state_
 * 
 * @return State 
 */
State Cell::GetState() const {
  return state_;
}

/**
 * @brief Setter de tate_
 * 
 * @param state 
 */
void Cell::SetState(State state) {
  state_ = state;  
}

/**
 * @brief Getter de position_
 * 
 * @return std::pair<int, int> 
 */
std::pair<int, int> Cell::GetPosition() const {
  return position_;
}

/**
 * @brief Setter de position_
 * 
 * @param position 
 */
void Cell::SetPosition(std::pair<int, int> position) {
  position_ = position;
}

/**
 * @brief Método para actualizar el estado de la célula según el número de vecinos "vivos"
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
 * @brief Método que comprueba el estado de los vecinos alrededor de la célula
 * 
 * @return int Cantidad de vecinos vivos
 */
int Cell::Neighbors(const Grid& grid) {
  live_neighbors_ = 0;  
  
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
 * @brief Salida por pantalla para mostrar la célula
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