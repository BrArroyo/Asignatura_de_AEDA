/**
 * Archivo state.h: Clase State.
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
 * @brief Estructura y definición de la clase State 
 * 
 * La función de la clase abstracta State sirve como interfaz de estado
 * para el programa
 *  
 * Historial de versiones:
 *   12/03/2022 - Ver 1.1 Inicio de la parte 2 de la práctica
 *   13/03/2022 - Ver 2.0 Versión terminada y comentada 
 *   20/03/2022 - Ver 2.1 Inicio de la parte 3 de la práctica 
 *   21/03/2022 - Ver 3.0 Versión terminada y comentada  
 */

class Cell;
class Grid;
class StateDead;
class StateAlive;

#ifndef LIFE_CYCLE_STATE_H_
#define LIFE_CYCLE_STATE_H_

#include <stdlib.h>
#include <unistd.h>


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
class State {  
  protected:
    Cell *cell_;

  public:
    virtual ~State() {}

    void SetCell(Cell *cell) {
      this->cell_ = cell;
    }

    virtual void Neighbors(const Grid&, int i, int j) = 0;

    virtual State* NextState() = 0;

    virtual char GetState() const = 0;
};

#endif  // LIFE_CYCLE_STATE_H_