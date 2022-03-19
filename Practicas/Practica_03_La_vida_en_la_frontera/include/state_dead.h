/**
 * Archivo state_dead.h: Clase StateDead.
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
 * @brief Estructura y definición de la clase StateDead 
 * 
 * La función de la clase concreta StateDead sirve como estado concreto
 * representando el estado muerto
 *  
 * Historial de versiones:
 *   12/03/2022 - Ver 1.1 Inicio de la parte 2 de la práctica
 *   13/03/2022 - Ver 2.0 Versión terminada y comentada
 *   20/03/2022 - Ver 2.1 Inicio de la parte 3 de la práctica    
 */

class Grid;
class State;

#ifndef LIFE_CYCLE_STATE_DEAD_H_
#define LIFE_CYCLE_STATE_DEAD_H_

#include <stdlib.h>
#include <unistd.h>

#include "grid.h"
#include "state.h"
#include "state_alive.h"

/**
 * @class StateDead
 * 
 * @brief Clase concreta para el estado muerto
 * 
 * Funciones:
 *   void Neighbors(const Grid& grid, int i, int j) override: Método que comprueba el estado de los vecinos alrededor de la célula
 *   State* NextState() override: Implementa la regla de transición para calcular el siguiente estado
 *   char GetState() const override: Método que implementa la identificación del estado
 * 
 * Atributos:
 *   int adult_neighbors_: Entero para registrar las células adultas alrededor 
 */
class StateDead : public State {
  public:    
    void Neighbors(const Grid& grid, int i, int j) override;

    State* NextState() override;

    char GetState() const override;
  
  private:
    int alive_neighbors_; 
};

#endif  // LIFE_CYCLE_STATE_DEAD_H_