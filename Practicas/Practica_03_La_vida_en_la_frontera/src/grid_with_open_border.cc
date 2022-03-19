/**
 * Archivo grid_with_open_border.cc: Clase GridWithOpenBorder.
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
 * @brief Desarrollo de las funciones de la clase Grid 
 * 
 * La función de la clase Grid es es representar una rejilla para el juego
 * de la vida
 *  
 * Historial de versiones:
 *   01/03/2022 - Ver 0.1 Creación y primera versión del código
 *   07/03/2022 - Ver 1.0 Versión terminada y comentada
 *   12/03/2022 - Ver 1.1 Inicio de la parte 2 de la práctica
 *   13/03/2022 - Ver 2.0 Versión terminada y comentada
 *   20/03/2022 - Ver 2.1 Inicio de la parte 3 de la práctica  
 */

#include "../include/grid_with_open_border.h"

/**
 * @brief Construct a new Grid:: Grid object
 * 
 * Inicializa los atributos, construye la rejilla dinamicamente y asigna las
 * posiciones de cada célula
 * 
 * @param row Filas de la rejilla
 * @param col Columnas de la rejilla
 * @param turns Turnos del juego de la vida
 */
GridWithOpenBorder::GridWithOpenBorder(int row, int col) {
  row_ = row + 2;
  col_ = col + 2;

  grid_ = new Cell*[row_];
  for (int i = 0; i < row_; ++i) {
    grid_[i] = new Cell[col_];
  }
  
  for (int i = 0; i < row_; ++i) {
    for (int j = 0; j < col_; ++j) {
      std::pair<int, int> position(i, j);  
      (*(grid_ + i) + j)->SetPosition(position);
    }  
  }
}

/**
 * @brief Destroy the Grid:: Grid object
 * 
 * Destruye la rejilla creada dinamicamente
 */
GridWithOpenBorder::~GridWithOpenBorder() {
  for (int i = 0; i < row_; ++i) {
    delete[] grid_[i];
  }
  delete[] grid_; 
}

/**
 * @brief Getter de una célula de la rejilla 
 * 
 * @param row 
 * @param col 
 * @return const Cell& 
 */
const Cell& GridWithOpenBorder::GetCell(int row, int col) {
  return *(*(grid_ + row) + col);
}


Cell& GridWithOpenBorder::GetCell(int row, int col) const {
  return *(*(grid_ + row) + col);
}

void GridWithOpenBorder::NextGeneration() {
  for (int i = 1; i < row_ - 1; ++i) {
    for (int j = 1; j < col_ - 1; ++j) {
      (*(grid_ + i) + j)->Neighbors(*this);  
    }
  }
  for (int i = 1; i < row_ - 1; ++i) {
    for (int j = 1; j < col_ - 1; ++j) {
      (*(grid_ + i) + j)->UpdateState();  
      }
  }

  *this >> std::cout;
}  


bool GridWithOpenBorder::SetInitPosition(int row, int col) {
  if (row < 0 || col < 0 || row > row_ - 3 || col > col_ - 3) {
    std::cout << "las coordenadas no son validas" << std::endl;    
    return false;
  }
  
  row = row + 1;
  col = col + 1;

  if ((*(grid_ + row) + col)->GetState() == 'X') {
    std::cout << "Hay una célula viva en esa posición" << std::endl;
    return false;  
  }
  
  (*(grid_ + row) + col)->SetState(new StateAlive); 
  return true;
}

/**
 * @brief Método para visualizar el juego de la vida
 * 
 * @param os valor de retorno
 * @param grid rejilla
 * @return std::ostream& 
 */
std::ostream& GridWithOpenBorder::operator>>(std::ostream& os) {
  os << "▄";
  for (int j = 0; j < col_ - 1; ++j) {
    os << "▄▄"; 
  } 
  os << std::endl;

  for (int i = 1; i < row_ - 1; ++i) {
    os << "▌";
    os << " ";  
    for (int j = 1; j < col_ - 1; ++j) {
      os << this->GetCell(i, j);
      os << " ";    
    }
    os << "▐";
    os << std::endl;    
  }

  os << "▀";
  for (int j = 0; j < col_ - 1; ++j) {
    os << "▀▀"; 
  }
  os << " ";

  return os;
}