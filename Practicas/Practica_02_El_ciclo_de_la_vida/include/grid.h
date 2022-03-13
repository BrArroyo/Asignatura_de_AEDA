/**
 * Archivo grid.h: Clase Grid.
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
 * @brief Estructura y definición de la clase Grid 
 * 
 * La función de la clase Grid es es representar una rejilla para el juego
 * de la vida
 *  
 * Historial de versiones:
 *   01/03/2022 - Ver 0.1 Creación y primera versión del código
 *   07/03/2022 - Ver 1.0 Versión terminada y comentada
 *   12/03/2022 - Ver 1.1 Inicio de la parte 2 de la práctica
 *   13/03/2022 - Ver 2.0 Versión terminada y comentada  
 */

class Cell;

#ifndef LIFE_CYCLE_GRID_H_
#define LIFE_CYCLE_GRID_H_

#include <stdlib.h>
#include <unistd.h>

#include "cell.h"
#include "state_dead.h"
#include "state_egg.h"
#include "state_larva.h"
#include "state_pupa.h"
#include "state_adult.h"

/**
 * @class Grid
 * 
 * @brief La función de la clase Grid es la representación de la rejilla
 * 
 * Funciones:
 *   Constructor parametrizado
 *   Destructor
 *   Getters
 *   bool SetInitCells(int, int): Método para indicar las primeras células vivas
 *   void PlayGame(): Método para inicializar el juego de la vida
 *   NextGeneration: Método para calcular, cambiar y mostrar el siguiente turno.
 *   void ViewGrid(): Método para visualizar el juego de la vida
 *   friend std::ostream& operator<<(std::ostream&, const Grid&): Método para visualizar el juego de la vida
 *   void SetPosition(): Método para asignar las posiciones a las células  
 * 
 * Atributos:
 *   int row_: Atributo que guarda las filas de la rejilla
 *   int col_: Atributo que guarda las columnas de la rejilla
 *   int turns_: Atributo que guarda los turnos del juego de la vida
 *   Cell **grid_: Atributo para representar la rejilla de células  
 *   
 */
class Grid {
  public:
    Grid(int row, int col, int turns);
    ~Grid();

    const Cell& GetCell(int, int) const;
    int GetRow() const;
    int GetCol() const; 

    bool SetInitCells(int, int, char);
    
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

#endif  // LIFE_CYCLE_GRID_H_