/**
 * @file main.cc
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Dada una matriz compuesta por colores, una posición de comienzo y un 
 * color, modificar el color de la matriz a partir de la posición de comienzo.
 * 
 * @version 1.0
 * @date 2022-04-13  
 */


#include <iomanip>
#include <iostream>
#include <queue>

int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int column[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isSafe(std::vector<std::vector<char>> const &matrix, int x, int y, char target) {
  return (x >= 0 && x < matrix.size()) && (y >= 0 && y < matrix[0].size()) && matrix[x][y] == target;
}

void FloodFill(std::vector<std::vector<char>> &matrix, int x, int y, char replacement) {
  if (matrix.size() == 0) {
    return;
  }
  std::queue<std::pair<int, int>> queue;
  queue.push({x, y});
  char target = matrix[x][y];
  if (target == replacement) {
    return;
  }
  while (!queue.empty()) {
    std::pair<int, int> node = queue.front();
    queue.pop();
    int x = node.first;
    int y = node.second;
    matrix[x][y] = replacement;
    for (int k = 0; k < 8; k++) {
      if (isSafe(matrix, x + row[k], y + column[k], target)) {
        queue.push({x + row[k], y + column[k]});
      }
    }
  }
}

void PrintMatrix(std::vector<std::vector<char>> const &matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      std::cout << std::setw(3) << matrix[i][j];
    }
    std::cout << std::endl;
  }
}

int main() {
  std::vector<std::vector<char>> matrix = {
      {'Y', 'Y', 'Y', 'G', 'G', 'G', 'G', 'G', 'G', 'G'},
      {'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'G', 'X', 'X', 'X'},
      {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'X', 'X', 'X'},
      {'W', 'W', 'W', 'W', 'W', 'G', 'G', 'G', 'G', 'X'},
      {'W', 'R', 'R', 'R', 'R', 'R', 'G', 'X', 'X', 'X'},
      {'W', 'W', 'W', 'R', 'R', 'G', 'G', 'X', 'X', 'X'},
      {'W', 'B', 'W', 'R', 'R', 'R', 'R', 'R', 'R', 'X'},
      {'W', 'B', 'B', 'B', 'B', 'R', 'R', 'X', 'X', 'X'},
      {'W', 'B', 'B', 'X', 'B', 'B', 'B', 'B', 'X', 'X'},
      {'W', 'B', 'B', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}};
  int x = 3;
  int y = 9;
  char replacement = 'C';
  FloodFill(matrix, x, y, replacement);
  PrintMatrix(matrix);
  return 0;
}