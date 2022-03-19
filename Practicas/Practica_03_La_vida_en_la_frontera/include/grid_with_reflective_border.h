/**
 * Archivo grid_with_reflective_border.h: Clase GridWithReflectiveBorder.
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
 * @brief Estructura y definición de la clase GridWithReflectiveBorder 
 * 
 * La función de la clase GridWithReflectiveBorder es representar una rejilla frontera reflectiva para el juego
 * de la vida
 *  
 * Historial de versiones:
 *   20/03/2022 - Ver 2.1 Inicio de la parte 3 de la práctica    
 */

class Cell;
class Grid;

#ifndef LIFE_CYCLE_GRID_WITH_REFLECTIVE_BORDER_H_
#define LIFE_CYCLE_GRID_WITH_REFLECTIVE_BORDER_H_

#include <stdlib.h>
#include <unistd.h>

#include "cell.h"
#include "grid.h"
#include "state_dead.h"
#include "state_alive.h"

/**
 * @class GridWithReflectiveBorder
 * 
 * @brief La función de la clase GridWithReflectiveBorder es la representación de la rejilla de frontera reflectiva
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
 *   Cell **grid_: Atributo para representar la rejilla de células  
 *   
 */
class GridWithReflectiveBorder : public Grid {
  public:
    GridWithReflectiveBorder(int row, int col);
    ~GridWithReflectiveBorder();

    const Cell& GetCell(int, int) override;
    Cell& GetCell(int, int) const override;

    void NextGeneration() override;

    bool SetInitPosition(int , int) override;

    std::ostream& operator>>(std::ostream& os) override;

  private:
    int row_;
    int col_;
    Cell **grid_;    
};

#endif  // LIFE_CYCLE_GRID_WITH_REFLECTIVE_BORDER_H_