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
  int i, j, k, max, x;
  int aux[N]; 

  // Elementos de posiciones impares: 
  // inserción de menor a mayor
  for (i = 3; i < N; i+=2) {
    x = sec[i];
    j = i;
    while (( x < sec[j - 2]) && (j > 1)) {
      sec[j] = sec[j - 2];
      j-= 2;
    }
    sec[j] = x;
  }
 
  // Elementos de posiciones pares: 
  // selección de mayor a menor
  for (i = 0; i < N-1; i+=2) {
    max = i;
    for (j = i + 2; j < N; j+=2) { 
      if (sec[j] > sec[max]) { 
        max = j;
      }  
    }    
    x = sec[max];
    sec[max] = sec[i];
    sec[i] = x;
  }  

  // Mezclar las dos subsecuencias de menor a mayor 
  if (N % 2 == 0) {    // Subsecuencia posiciones pares 
    i = N - 2;
  } else {
    i = N - 1; 
  }
  j = 1;              // Subsecuencia posiciones impares 
  k = 0;
  while ((i >= 0) && (j <= N-1)) {
    if (sec[i] < sec[j]) {
      aux[k] = sec[i];
      i-=2;
    } else {
      aux[k] = sec[j];  
      j+=2;
    }
    k++;
  }

  // Se copia la subsecuencia no completa
  if (i < 0) { 
    while (j <= N-1) {
      aux [k] = sec[j];
      j+=2; k++;
    }
  } else {
    while (i >= 0) {
      aux[k] = sec[i];
      i-=2; k++;
    }
  }
  // Se copia al array original
  for (i = 0; i < N; i++) {
    sec[i] = aux[i];
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