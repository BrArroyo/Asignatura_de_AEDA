/**
 * Archivo grid.h: Clase Grip.
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
 * @brief Estructura y definición de la clase Grip 
 * 
 * La función de la clase Grip es 
 *  
 * Historial de versiones:
 *   01/03/2022 - Ver 0.1 Creación y primera versión del código
 */

class Cell;

#ifndef LIFE_GAME_GRID_H_
#define LIFE_GAME_GRID_H_

#include <stdlib.h>
#include <unistd.h>

#include "cell.h"

/**
 * @class Grid
 * 
 * @brief La función de la clase Grid es la representación de la rejilla
 * 
 * Funciones:
 *   Constructor
 *   Destructor
 * 
 * Atributos:  
 */
class Grid {
  public:
    Grid(int row, int col, int turns);
    ~Grid();

    const Cell& GetCell(int, int) const;
    int GetRow() const;
    int GetCol() const; 

    bool SetInitCells(int, int);
    
    void PlayGame();

    void NextGeneration();
    
    void ViewGrid();
    friend std::ostream& operator<<(std::ostream&, const Grid&);

  private:
    void SetPosition();

    int row_;
    int col_;
    int turns_;    
    Cell **grid_;    
};

#endif  // LIFE_GAME_GRID_H_