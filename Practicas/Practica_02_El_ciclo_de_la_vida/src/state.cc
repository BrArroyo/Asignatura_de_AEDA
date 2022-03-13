/**
 * Archivo state.h: Clase State.
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
 * @brief Estructura y definición de la clase State 
 * 
 * La función de la clase abstracta State sirve como interfaz de estado
 * para el programa
 *  
 * Historial de versiones:
 *   12/03/2022 - Ver 1.1 Inicio de la parte 2 de la práctica 
 */

class Cell;

#ifndef LIFE_CYCLE_STATE_H_
#define LIFE_CYCLE_STATE_H_

#include <stdlib.h>
#include <unistd.h>

#include "cell.h"
#include "grid.h"

/**
 * @class State
 * 
 * @brief Clase abstracta para los estados de la célula
 * 
 * Funciones:
 *   virtual ~State() {}
 *   void SetCell(Cell *cell) 
 *   virtual void Neighbors(const Grid&, int i, int j) = 0: Método que comprueba el estado de los vecinos alrededor de la célula
 *   virtual State* NextState() = 0: Implementa la regla de transición para calcular el siguiente estado
 *   virtual char GetState() const = 0: Método que implementa la identificación del estado
 */

#include "../include/state.h"



void State::SetCell(Cell *cell) {
  this->cell_ = cell;
}


