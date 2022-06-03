#include <iostream>
#include <fstream>

// Escribe un procedimiento en C++ que ordene de menor a mayor por el método de 
// ordenación por inserción los elementos de las posiciones impares entre sí, y 
// luego ordene de mayor a menor por el método de ordenación por selección los 
// elementos de las posiciones pares, y finalmente mezcle ambas partes.
void Sort(int *sec, int N) {
  int i, j, k, max, x;
  int mitad = N / 2;
  int aux[N]; 
  
  //Insertion for odd index Menor --> Mayor
  for (int i = 1; i < N; ++i) {
    if (i % 2 != 0) {
      x = sec[i];
      j = i;
      while (( x < sec[j - 2]) && (j > 1)) {
        sec[j] = sec[j - 2];
        j-=2;
      }
      sec[j] = x;
    }
  }

  //Selection for even index Mayor --> Menor
  for (int i = 0; i < N - 1; i++) {
    if (i % 2 == 0) {
      max = i;
      for (int j = i + 2; j <= N - 1; j += 2) {
        if (sec[j] > sec[max]) 
          max = j;
      }

      x = sec[max];
      sec[max] = sec[i];
      sec[i] = x;
    }
  }
  
  //Mezcla -> i para mayor a menor || -> j para nemor a mayor
  // como queremos un array de menor a mayor recorremos en cada sentido, para las i vamos de drch a iqz, y para la j al reves
  if (N % 2 == 0) i = N - 2;
  else i = N - 1;
  j = 1;
  k = 0;
  while ((i >= 0) && (j <= N - 1)) {
    if (sec[i] < sec[j]) {
      aux[k] = sec[i];
      i -= 2;
    } else {
      aux[k] = sec[j];
      j += 2;
    }
    k++;
  }

  //Subsecuencia no completa
  if (i < 0)
    while (j <= N - 1) {
      aux[k] = sec[j];
      j += 2;
      k++;
    }
  else 
    while (i >= 0) {
      aux[k] = sec[i];
      i -= 2;
      k++;
    }
  
  //Copiar
  for (int i = 0; i < N; i++) 
    sec[i] = aux[i];
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
