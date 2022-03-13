/**
 * Archivo state_adult.h: Clase StateAdult.
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
 * @brief Estructura y definición de la clase StateAdult 
 * 
 * La función de la clase concreta StateAdult sirve como estado concreto
 * representando el estado adulto
 *  
 * Historial de versiones:
 *   12/03/2022 - Ver 1.1 Inicio de la parte 2 de la práctica
 *   13/03/2022 - Ver 2.0 Versión terminada y comentada  
 */

class Grid;
class State;

#ifndef LIFE_CYCLE_STATE_ADULT_H_
#define LIFE_CYCLE_STATE_ADULT_H_

#include <stdlib.h>
#include <unistd.h>

#include "grid.h"
#include "state.h"
#include "state_dead.h"
#include "state_egg.h"


/**
 * @class StateAdult
 * 
 * @brief Clase concreta para el estado adulta
 * 
 * Funciones:
 *   void Neighbors(const Grid& grid, int i, int j) override: Método que comprueba el estado de los vecinos alrededor de la célula
 *   State* NextState() override: Implementa la regla de transición para calcular el siguiente estado
 *   char GetState() const override: Método que implementa la identificación del estado
 * 
 * Atributos:
 *   int adult_neighbors_: Entero para registrar las células adult alrededor
 */
class StateAdult : public State {
  public:    
    void Neighbors(const Grid& grid, int i, int j) override;

    State* NextState() override;

    char GetState() const override;

  private:
    int adult_neighbors_;   
};

#endif  // LIFE_CYCLE_STATE_ADULT_H_