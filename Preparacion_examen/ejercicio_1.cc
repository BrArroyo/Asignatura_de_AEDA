#include <iostream>
#include <fstream>

// Escribe un procedimiento en C++ que ordene la primera mitad de la secuencia o vector 
// por el método de selección de menor a mayor, luego ordene la segunda mitad también por el método de inserción, 
// pero de mayor a menor, y finalmente mezcle ambas mitades de forma que el vector 
// quede ordenado de mayor a menor ordenada.
void Sort(int *sec, int N) {
  int i, j, k, min, x;
  int mitad = N / 2;
  int aux[N]; 

  //  Primera mitad [0, mitad]: 
  //  selección de menor a mayor
  for (i = 0; i < mitad; i++) {
    min = i;
    for (j = i + 1; j <= mitad; j++) { 
      if (sec[j] < sec[min]) { 
        min = j;
      }  
    }    
    x = sec[min];
    sec[min] = sec[i];
    sec[i] = x;
  }   

  //  Segunda mitad [mitad+1, N-1]: 
  //  inserción de mayor a menor
  for (i = mitad + 2; i < N; i++) {
    x = sec[i];
    j = i;
    while (( x > sec[j - 1]) && (j > mitad + 1)) {
      sec[j] = sec[j - 1];
      j--;
    }
    sec[j] = x;
  }

  // Mezclar las dos mitades de mayor a menor
  i = mitad; 
  j = mitad + 1;   
  k = 0;
  while ((i >= 0) && (j < N)) {
    if (sec[i] > sec[j]) {
      aux[k] = sec[i];
      i--;
    } else {
      aux[k] = sec[j];  
      j++;
    }
    k++;
  }

  // Se copia la subsecuencia no completa
  if (i < 0) { 
    while (j < N) {
      aux [k] = sec[j];
      j++; k++;
    }
  } else {
    while (i >= 0) {
      aux[k] = sec[i];
      i--; k++;
    }
  }
 
  // Se copia al array original
  for (i = 0; i < N; i++) {
    sec[i] = aux[i];
  }
}


int main(int argc, char * argv[]) {  
  int vector[] = {44, 55, 7, 42, 16, 40, 94, 12};
  int size = 8;
  
  for (int i = 0; i < size; ++i) {
    std::cout << vector[i] << " ";
  }

  Sort(vector, size);
  
  std::cout << std::endl;
  for (int i = 0; i < size; ++i) {
    std::cout << vector[i] << " ";
  }

  std::cout << std::endl;
  std::cout << "Programa Finalizado" << std::endl;
  return 0;
}

