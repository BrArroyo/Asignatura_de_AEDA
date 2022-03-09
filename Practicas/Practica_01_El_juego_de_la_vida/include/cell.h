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
 * @brief Estructura y definición de la clase Cell 
 * 
 * La función de la clase Cell es representar una célula para el juego
 * de la vida
 *  
 * Historial de versiones:
 *   01/03/2022 - Ver 0.1 Creación y primera versión del código
 *   07/03/2022 - Ver 1.0 Versión terminada y comentada
 */

class Grid;

#ifndef LIFE_GAME_CELL_H_
#define LIFE_GAME_CELL_H_

#include <iostream>

#include "grid.h"

enum State {dead = 0, live = 1};

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
 *   int live_neighbors_: Atributo que guarda cuantos vecinos están "vivos"
 *   State state_: Atributo que guarda el estado actual de la célula
 *   std::pair<int, int> position_: Atributo que guarda la posición de la célula en la rejilla.       
 */
class Cell {
  public:
    Cell();
    ~Cell();

    State GetState() const;
    void SetState(State);

    std::pair<int, int> GetPosition() const;
    void SetPosition(std::pair<int, int>);
        
    void UpdateState();
    int Neighbors(const Grid&); 
    
    friend std::ostream& operator<<(std::ostream&, const Cell&);    

  private:
    int live_neighbors_;  
    State state_;
    std::pair<int, int> position_;  
};

#endif  // LIFE_GAME_CELL_H_