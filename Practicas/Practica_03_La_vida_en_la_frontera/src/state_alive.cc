/**
 * Archivo state_alive.cc: Clase StateAlive.
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
 * @brief Desarrollo de las funciones de la clase StateDead 
 * 
 * La función de la clase concreta StateDead sirve como estado concreto
 * representando el estado muerto
 *  
 * Historial de versiones:
 *   20/03/2022 - Ver 2.1 Inicio de la parte 3 de la práctica
 *   21/03/2022 - Ver 3.0 Versión terminada y comentada  
 */

#include "../include/state_alive.h"

/**
 * @brief Método que comprueba el estado de los vecinos alrededor de la célula
 * 
 * @param grid rejilla de células
 * @param i fila de la célula 
 * @param j columna de la célula
 */
void StateAlive::Neighbors(const Grid& grid, int i, int j) {
  alive_neighbors_ = 0;
  char aux = ' ';

  // i - 1, j - 1
  aux = grid.GetCell(i - 1, j - 1).GetState();
  switch (aux) {
    case 'X':
      ++alive_neighbors_;
      break;
    default:
      break;   
  }
  
  // i - 1, j
  aux = grid.GetCell(i - 1, j).GetState();
  switch (aux) {
    case 'X':
      ++alive_neighbors_;
      break;
    default:
      break;   
  }
  
  // i - 1, j + 1
  aux = grid.GetCell(i - 1, j + 1).GetState();
  switch (aux) {
    case 'X':
      ++alive_neighbors_;
      break;  
    default:
      break;   
  }
  
  // i, j - 1
  aux = grid.GetCell(i, j - 1).GetState();
  switch (aux) {
    case 'X':
      ++alive_neighbors_;
      break;
    default:
      break;   
  }
  
  // i, j + 1  
  aux = grid.GetCell(i, j + 1).GetState();
  switch (aux) {
    case 'X':
      ++alive_neighbors_;
      break;
    default:
      break;   
  }
  
  // i + 1, j - 1  
  aux = grid.GetCell(i + 1, j - 1).GetState();
  switch (aux) {
    case 'X':
      ++alive_neighbors_;
      break;
    default:
      break;   
  }
  
  // i + 1, j  
  aux = grid.GetCell(i + 1, j).GetState();
  switch (aux) {
    case 'X':
      ++alive_neighbors_;
      break;
    default:
      break;   
  }
  
  // i + 1, j + 1 
  aux = grid.GetCell(i + 1, j + 1).GetState();
  switch (aux) { 
    case 'X':
      ++alive_neighbors_;
      break;
    default:
      break;   
  }
}

/**
 * @brief Implementa la regla de transición para calcular el siguiente estado
 * 
 * @return State* Sigiente estado
 */
State* StateAlive::NextState() {
  if (alive_neighbors_ == 2 || alive_neighbors_ == 3) {
    return new StateAlive;   
  } else {
    return new StateDead;
  }   
}

/**
 * @brief Método que implementa la identificación del estado
 * 
 * @return char Devuelve el identificador del estado
 */
char StateAlive::GetState() const {
  return 'X';
}