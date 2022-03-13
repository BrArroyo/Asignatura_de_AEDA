/**
 * Archivo state_larva.cc: Clase StateLarva.
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzados
 * Curso: 2º
 * Práctica 02: El ciclo de la vida 
 *
 * @author Bruno Lorenzo Arroyo Pedraza
 * @email alu0101123677@ull.edu.es
 * @date 12/03/2022
 * 
 * @brief Desarrollo de las funciones de la clase StateLarva 
 * 
 * La función de la clase concreta StateLarva sirve como estado concreto
 * representando el estado larva
 *  
 * Historial de versiones:
 *   12/03/2022 - Ver 1.1 Inicio de la parte 2 de la práctica
 *   13/03/2022 - Ver 2.0 Versión terminada y comentada  
 */

#include "../include/state_larva.h"

/**
 * @brief Método que comprueba el estado de los vecinos alrededor de la célula
 * 
 * @param grid rejilla de células
 * @param i fila de la célula 
 * @param j columna de la célula
 */
void StateLarva::Neighbors(const Grid& grid, int i, int j) {
  egg_neighbors_ = 0;
  larva_neighbors_ = 0;
  pupa_neighbors_ = 0;
  adult_neighbors_ = 0;
  char aux = ' ';

  // i - 1, j - 1
  aux = grid.GetCell(i - 1, j - 1).GetState();
  switch (aux) {
    case 'H':
      ++egg_neighbors_;
      break;
    case 'L':
      ++larva_neighbors_;
      break;
    case 'P':
      ++pupa_neighbors_;
      break;
    case 'A':
      ++adult_neighbors_;
      break;
    default:
      break;   
  }
  
  // i - 1, j
  aux = grid.GetCell(i - 1, j).GetState();
  switch (aux) {
    case 'H':
      ++egg_neighbors_;
      break;
    case 'L':
      ++larva_neighbors_;
      break;
    case 'P':
      ++pupa_neighbors_;
      break;
    case 'A':
      ++adult_neighbors_;
      break;
    default:
      break;   
  }
  
  // i - 1, j + 1
  aux = grid.GetCell(i - 1, j + 1).GetState();
  switch (aux) {
    case 'H':
      ++egg_neighbors_;
      break;
    case 'L':
      ++larva_neighbors_;
      break;
    case 'P':
      ++pupa_neighbors_;
      break;
    case 'A':
      ++adult_neighbors_;
      break;
    default:
      break;   
  }
  
  // i, j - 1
  aux = grid.GetCell(i, j - 1).GetState();
  switch (aux) {
    case 'H':
      ++egg_neighbors_;
      break;
    case 'L':
      ++larva_neighbors_;
      break;
    case 'P':
      ++pupa_neighbors_;
      break;
    case 'A':
      ++adult_neighbors_;
      break;
    default:
      break;   
  }
  
  // i, j + 1  
  aux = grid.GetCell(i, j + 1).GetState();
  switch (aux) {
    case 'H':
      ++egg_neighbors_;
      break;
    case 'L':
      ++larva_neighbors_;
      break;
    case 'P':
      ++pupa_neighbors_;
      break;
    case 'A':
      ++adult_neighbors_;
      break;
    default:
      break;   
  }
  
  // i + 1, j - 1  
  aux = grid.GetCell(i + 1, j - 1).GetState();
  switch (aux) {
    case 'H':
      ++egg_neighbors_;
      break;
    case 'L':
      ++larva_neighbors_;
      break;
    case 'P':
      ++pupa_neighbors_;
      break;
    case 'A':
      ++adult_neighbors_;
      break;
    default:
      break;   
  }
  
  // i + 1, j  
  aux = grid.GetCell(i + 1, j).GetState();
  switch (aux) {
    case 'H':
      ++egg_neighbors_;
      break;
    case 'L':
      ++larva_neighbors_;
      break;
    case 'P':
      ++pupa_neighbors_;
      break;
    case 'A':
      ++adult_neighbors_;
      break;
    default:
      break;   
  }
  
  // i + 1, j + 1 
  aux = grid.GetCell(i + 1, j + 1).GetState();
  switch (aux) {
    case 'H':
      ++egg_neighbors_;
      break;
    case 'L':
      ++larva_neighbors_;
      break;
    case 'P':
      ++pupa_neighbors_;
      break;
    case 'A':
      ++adult_neighbors_;
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
State* StateLarva::NextState() {
  if (larva_neighbors_ > egg_neighbors_ + pupa_neighbors_ + adult_neighbors_) {
    return new StateDead;
  } else {
    return new StatePupa;
  }
}

/**
 * @brief Método que implementa la identificación del estado
 * 
 * @return char Devuelve el identificador del estado
 */
char StateLarva::GetState() const {
  return 'L';
}