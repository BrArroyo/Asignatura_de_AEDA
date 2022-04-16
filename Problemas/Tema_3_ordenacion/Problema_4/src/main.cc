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
  int i, j, f, piv, x;

  i = 0;
  f = N - 1;
  piv = sec[(i + f) / 2];

  while (i <= f) {
    // Recorrido ascendente
    while (sec[i] <= piv) {        
      x = sec[i];
      j = i;
      while (( x < sec[j - 1]) && (j > 0)) {
        sec[j] = sec[j - 1];
        j--;
      }
      sec[j] = x;
      i++;
    }
    // Recorrido descendente
    while (sec[f] >= piv)  {    
      x = sec[f];
      j = f;
      while (( x > sec[j + 1]) && (j < N)) {
        sec[j] = sec[j + 1];
        j++;
      }
      sec[j] = x;
      f--;
    }

    // Intercambio de valores
    if (i <= f) {            
      x = sec[i];
      sec[i] = sec[f];
      sec[f] = x;
    }

  }  // while (i <= f)
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


