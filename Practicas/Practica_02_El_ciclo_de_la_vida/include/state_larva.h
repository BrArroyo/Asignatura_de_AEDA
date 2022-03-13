/**
 * Archivo state_larva.h: Clase StateLarva.
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
 * @brief Estructura y definición de la clase StateLarva 
 * 
 * La función de la clase concreta StateLarva sirve como estado concreto
 * representando el estado larva
 *  
 * Historial de versiones:
 *   12/03/2022 - Ver 1.1 Inicio de la parte 2 de la práctica
 *   13/03/2022 - Ver 2.0 Versión terminada y comentada  
 */

class Grid;
class State;

#ifndef LIFE_CYCLE_STATE_LARVA_H_
#define LIFE_CYCLE_STATE_LARVA_H_

#include <stdlib.h>
#include <unistd.h>

#include "grid.h"
#include "state.h"
#include "state_dead.h"
#include "state_pupa.h"

/**
 * @class StateLarva
 * 
 * @brief Clase concreta para el estado larva
 * 
 * Funciones:
 *   void Neighbors(const Grid& grid, int i, int j) override: Método que comprueba el estado de los vecinos alrededor de la célula
 *   State* NextState() override: Implementa la regla de transición para calcular el siguiente estado
 *   char GetState() const override: Método que implementa la identificación del estado
 * 
 * Atributos:
 *   int egg_neighbors_: Entero para registrar las células huevo alrededor
 *   int larva_neighbors_: Entero para registrar las células larva alrededor
 *   int pupa_neighbors_: Entero para registrar las células pupa alrededor
 *   int adult_neighbors_: Entero para registrar las células adult alrededor
 */
class StateLarva : public State {
  public:    
    void Neighbors(const Grid& grid, int i, int j) override;

    State* NextState() override;

    char GetState() const override;
  
  private:
    int egg_neighbors_;
    int larva_neighbors_;
    int pupa_neighbors_;
    int adult_neighbors_;  
};

#endif  // LIFE_CYCLE_STATE_LARVA_H_