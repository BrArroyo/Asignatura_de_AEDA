/**
 * Archivo grid.h: Clase Grid.
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
 * @brief Estructura y definición de la clase Grid 
 * 
 * La función de la clase abstracta Grid es es representar una rejilla para el juego
 * de la vida
 *  
 * Historial de versiones:
 *   20/03/2022 - Ver 2.1 Inicio de la parte 3 de la práctica    
 */

class Cell;
class GridWithOpenBorder;
class GridWithPeriodicBorder;
class GridWithReflectiveBorder;

#ifndef LIFE_CYCLE_GRID_H_
#define LIFE_CYCLE_GRID_H_

#include <stdlib.h>
#include <unistd.h>

#include "cell.h"
#include "state_dead.h"
#include "state_alive.h"

/**
 * @class Grid
 * 
 * @brief La función de la clase Grid es la representación de la rejilla
 * 
 * Funciones:
 * 
 * Atributos:
 *   
 */
class Grid {
  public:
    virtual ~Grid() {}

    virtual const Cell& GetCell(int, int) =0;
    virtual Cell& GetCell(int, int) const =0;

    virtual void NextGeneration() =0;

    virtual bool SetInitPosition(int , int) =0;
    
    virtual std::ostream& operator>>(std::ostream& os) =0;      
};

#endif  // LIFE_CYCLE_GRID_H_