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
}

Cell::~Cell() {

}

State Cell::GetState() const {
  return state_;
}


void Cell::SetState(State state) {
  state_ = state;  
}

/**
 * @brief 
 * 
 */
void Cell::UpdateState() {

}

/**
 * @brief 
 * 
 * @return int 
 */
int Cell::Neighbors(const Grid&) {
 return 1;
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

