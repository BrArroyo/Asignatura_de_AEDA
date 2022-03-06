/**
 * Archivo grid.cc: Clase Grip.
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
 * @brief Desarrollo de las funciones de la clase Grip 
 * 
 * La función de la clase Grip es 
 *  
 * Historial de versiones:
 *   01/03/2022 - Ver 0.1 Creación y primera versión del código
 */

#include "../include/grid.h"

Grid::Grid(int row, int col, int turns) {
  row_ = row + 2;
  col_ = col + 2;
  turns_ = turns;

  grid_ = new Cell*[row_];
  for (int i = 0; i < row_; ++i) {
    grid_[i] = new Cell[col_];
  }
  
  SetPosition();
}

Grid::~Grid() {
  for (int i = 0; i < row_; ++i) {
    delete[] grid_[i];
  }
  delete[] grid_; 
}

const Cell& Grid::GetCell(int row, int col) const {
  return *(*(grid_ + row) + col);
}

int Grid::GetRow() const {
  return row_;
}

int Grid::GetCol() const {
  return col_;
} 

bool Grid::SetInitCells(int row, int col) {
  if (row < 0 || col < 0 || row > row_ - 3 || col > col_ - 3) {
    std::cout << "las coordenadas no son validas" << std::endl;    
    return false;
  }
  
  row = row + 1;
  col = col + 1;

  if ((*(grid_ + row) + col)->GetState() == live) {
    std::cout << "la celula en esa posición esta viva" << std::endl;  
    return false;
  }
  
  (*(grid_ + row) + col)->SetState(live);
  return true;
}


void Grid::PlayGame() {
  std::cout << "Iniciando el juego de la vida" << std::endl;
  std::cout << "mostrando las células" << std::endl;
  std::cout << "Turno: 0" << std::endl; 
  ViewGrid();
  std::cout << std::endl;
  for (int i = 1; i <= turns_; ++i) {
    std::cout << "Turno: " << i << std::endl;
    NextGeneration(); 
    std::cout << std::endl;    
    sleep(1);
  }
  std::cout << "Juego de la vida terminado" << std::endl;
}


void Grid::NextGeneration() {
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
  ViewGrid();
}


void Grid::ViewGrid() {
  std::cout << "▄";
  for (int j = 0; j < col_ - 1; ++j) {
    std::cout << "▄▄"; 
  } 
  std::cout << std::endl;

  for (int i = 1; i < row_ - 1; ++i) {
    std::cout << "▌";
    std::cout << " ";  
    for (int j = 1; j < col_ - 1; ++j) {
      std::cout << GetCell(i, j);
      std::cout << " ";    
    }
    std::cout << "▐";
    std::cout << std::endl;    
  }

  std::cout << "▀";
  for (int j = 0; j < col_ - 1; ++j) {
    std::cout << "▀▀"; 
  }
}

std::ostream& operator<<(std::ostream& os, const Grid& grid) {
  os << "▄";
  for (int j = 0; j < grid.GetCol() - 1; ++j) {
    os<< "▄▄"; 
  } 
  os << std::endl;

  for (int i = 1; i < grid.GetRow() - 1; ++i) {
    os << "▌";
    os << " ";  
    for (int j = 1; j < grid.GetCol() - 1; ++j) {
      os << grid.GetCell(i, j);
      os << " ";    
    }
    os << "▐";
    os << std::endl;    
  }

  os << "▀";
  for (int j = 0; j < grid.GetCol() - 1; ++j) {
    os << "▀▀"; 
  }

  return os;
}

void Grid::SetPosition() {
  for (int i = 0; i < row_; ++i) {
    for (int j = 0; j < col_; ++j) {
      std::pair<int, int> position(i, j);  
      (*(grid_ + i) + j)->SetPosition(position);
    }  
  }
}


