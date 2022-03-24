/**
 * Archivo cell.h: Clase Cell.
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzados
 * Curso: 2º
 * Práctica 03: La vida en la frontera
 *
 * @author Bruno Lorenzo Arroyo Pedraza
 * @email alu0101123677@ull.edu.es
 * @date 20/02/2022
 * 
 * @brief Desarrollo de las funciones de la clase Cell 
 * 
 * La función de la clase Cell es representar una célula para el juego
 * de la vida 
 *  
 * Historial de versiones:
 *   01/03/2022 - Ver 0.1 Creación y primera versión del código
 *   07/03/2022 - Ver 1.0 Versión terminada y comentada
 *   12/03/2022 - Ver 1.1 Inicio de la parte 2 de la práctica
 *   13/03/2022 - Ver 2.0 Versión terminada y comentada
 *   20/03/2022 - Ver 2.1 Inicio de la parte 3 de la práctica
 *   21/03/2022 - Ver 3.0 Versión terminada y comentada  
 */

#include "../include/cell.h"

/**
 * @brief Construct a new Cell:: Cell object
 * 
 */
Cell::Cell() {
  state_ = nullptr;
  this->SetState(new StateDead);
}

/**
 * @brief Destroy the Cell:: Cell object
 * 
 */
Cell::~Cell() {
  delete state_;
}

char Cell::GetState() const {
  return this->state_->GetState();
}

void Cell::SetState(State* state) {
  if (this->state_ != nullptr)
    delete this->state_;
  this->state_ = state;
  this->state_->SetCell(this);
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
  SetState(this->state_->NextState());
}

/**
 * @brief Método que comprueba el estado de los vecinos alrededor de la célula
 * 
 * @return int Cantidad de vecinos vivos
 */
void Cell::Neighbors(const Grid& grid) {
  this->state_->Neighbors(grid, position_.first, position_.second);
}

/**
 * @brief Salida por pantalla para mostrar la célula
 * 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Cell& cell) {
  os << cell.GetState();
  return os;
}