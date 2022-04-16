/**
 * @file main.cc
 * @author Bruno Lorenzo Arroyo Pedraza
 * @brief Ordena una secuencia según las instrucciones del readme
 * @version 1.0
 * @date 2022-04-16
 * 
 */

#include <iostream>

/**
 * @brief Función para ordenar la secuencia según el readme 
 * 
 * @param sec 
 * @param N 
 */
void Sort(int *sec, int N) {
  int i, j, k, f, min, piv, x;

  // Iteración de QuickSort: 
  // dividir la secuencia en dos
  i = 0;
  f = N - 1;
  piv = sec[(i + f) / 2];

  while (i <= f) {
    while (sec[i] < piv) i++;
    while (sec[f] > piv) f--;
    if (i <= f) {
      x = sec[i];
      sec[i] = sec[f];
      sec[f] = x;
      i++;
      f--;
    }
  }

  // Primera subsecuencia [0, f]: inserción
  for (k = 1; k <= f; k++) {
    x = sec[k];
    j = k;
    while (( x < sec[j - 1]) && (j > 0)) {
      sec[j] = sec[j - 1];
      j--;
    }
    sec[j] = x;
  }
 
  // Segunda subsecuencia [i, N-1]: selección
  for (k = i; k < N-1; k++) {
    min = k;
    for (j = k + 1; j < N; j++) {
      if (sec[j] < sec[min]) { 
        min = j;
      }  
    }    
    x = sec[min];
    sec[min] = sec[k];
    sec[k] = x;
  }  
}

/**
 * @brief Función main del programa
 * 
 * @return int 
 */
int main () {
  int vector[] = {3, 4, 5, 1, 2};
  int size = 5;
  
  for (int i = 0; i < size; ++i) {
    std::cout << vector[i] << " ";
  }

  Sort(vector, size);

  std::cout << std::endl;
  for (int i = 0; i < size; ++i) {
    std::cout << vector[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}

