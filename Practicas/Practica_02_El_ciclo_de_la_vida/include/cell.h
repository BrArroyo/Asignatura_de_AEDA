/**
 * Archivo cell.h: Clase Cell.
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
 * @brief Estructura y definición de la clase Cell 
 * 
 * La función de la clase Cell es representar una célula para el juego
 * de la vida
 *  
 * Historial de versiones:
 *   01/03/2022 - Ver 0.1 Creación y primera versión del código
 *   07/03/2022 - Ver 1.0 Versión terminada y comentada
 *   12/03/2022 - Ver 1.1 Inicio de la parte 2 de la práctica
 *   13/03/2022 - Ver 2.0 Versión terminada y comentada  
 */

class Grid;
class State;

#ifndef LIFE_CYCLE_CELL_H_
#define LIFE_CYCLE_CELL_H_

#include <iostream>

#include "grid.h"
#include "state.h"
#include "state_dead.h"
#include "state_egg.h"
#include "state_larva.h"
#include "state_adult.h"
#include "state_pupa.h"

/**
 * @class Cell
 * 
 * @brief La función de la clase Cell es la representación de la célula
 * 
 * Funciones:
 *   Constructor: Constructor por defecto
 *   Destructor: Destructor
 *   Setter y getters de los atributos
 *   void UpdateState(): Método para actualizar el estado de la célula según el número de vecinos "vivos"
 *   int Neighbors(const Grid&): Método que comprueba el estado de los vecinos alrededor de la célula
 *   friend std::ostream& operator<<(std::ostream&, const Cell&): salida por pantalla para mostrar la célula
 * 
 * Atributos:
 *   State *state_: Atributo que guarda el estado actual de la célula
 *   std::pair<int, int> position_: Atributo que guarda la posición de la célula en la rejilla.       
 */
class Cell {
  public:
    Cell();
    ~Cell();

    char GetState() const;
    void SetState(State*); 
    
    std::pair<int, int> GetPosition() const;
    void SetPosition(std::pair<int, int>);
        
    void UpdateState();

    void Neighbors(const Grid&); 
    
    friend std::ostream& operator<<(std::ostream&, const Cell&);    

  private:
    State *state_;
    std::pair<int, int> position_;  
};

#endif  // LIFE_CYCLE_CELL_H_