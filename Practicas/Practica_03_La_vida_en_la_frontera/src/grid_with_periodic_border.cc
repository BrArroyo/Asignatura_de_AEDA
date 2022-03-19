/**
 * Archivo grid_with_periodic_border.cc: Clase GridWithPeriodicBorder.
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
 * @brief Desarrollo de las funciones de la clase GridWithPeriodicBorder 
 * 
 * La función de la clase GridWithPeriodicBorder es es representar una rejilla con borde peridodico
 * para el juego de la vida
 *  
 * Historial de versiones:
 *   20/03/2022 - Ver 2.1 Inicio de la parte 3 de la práctica  
 */

#include "../include/grid_with_periodic_border.h"

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
GridWithPeriodicBorder::GridWithPeriodicBorder(int row, int col) {
  row_ = row;
  col_ = col;

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
GridWithPeriodicBorder::~GridWithPeriodicBorder() {
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
const Cell& GridWithPeriodicBorder::GetCell(int row, int col) {
  return *(*(grid_ + row) + col);
}


Cell& GridWithPeriodicBorder::GetCell(int row, int col) const {
  if (row == -1 && col == -1) {  // Esquina superior izquierda
    return *(*(grid_ + row_- 1) + col_ - 1);  
  } else if (row == -1 && col == col_) {   // Esquina superior derecha
    return *(*(grid_ + row_ -1) + 0);  
  } else if (row == row_ && col == -1) {   // Esquina inferior izquierda
    return *(*(grid_ + 0) + col_ - 1); 
  } else if (row == row_ && col == col_) { // Esquina inferior derecha
    return *(*(grid_ + 0) + 0);
  } else if (row == -1) {   // Lado superior
    return *(*(grid_ + row_ - 1) + col);
  } else if (row == row_) { // Lado inferior
    return *(*(grid_ + 0) + col);
  } else if (col == -1) {   // Lado izquierdo
    return *(*(grid_ + row) + col_ -1);
  } else if (col == col_) { // Lado derecho
    return *(*(grid_ + row) + 0);
  } 
  // Interior
  return *(*(grid_ + row) + col);
}

void GridWithPeriodicBorder::NextGeneration() {
  for (int i = 0; i < row_; ++i) {
    for (int j = 0; j < col_; ++j) {
      (*(grid_ + i) + j)->Neighbors(*this);  
    }
  }
  for (int i = 0; i < row_; ++i) {
    for (int j = 0; j < col_; ++j) {
      (*(grid_ + i) + j)->UpdateState();  
      }
  }

  *this >> std::cout;
}  


bool GridWithPeriodicBorder::SetInitPosition(int row, int col) {
  if (row < 0 || col < 0 || row >= row_ || col >= col_ ) {
    std::cout << "las coordenadas no son validas" << std::endl;    
    return false;
  }
  
  row = row;
  col = col;

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
std::ostream& GridWithPeriodicBorder::operator>>(std::ostream& os) {
  os << "▄";
  for (int j = 0; j < col_ + 1; ++j) {
    os << "▄▄"; 
  } 
  os << std::endl;

  for (int i = 0; i < row_; ++i) {
    os << "▌";
    os << " ";  
    for (int j = 0; j < col_; ++j) {
      os << this->GetCell(i, j);
      os << " ";    
    }
    os << "▐";
    os << std::endl;    
  }

  os << "▀";
  for (int j = 0; j < col_ + 1; ++j) {
    os << "▀▀"; 
  }
  os << " ";

  return os;
}