#include <iostream>
#include <fstream>

// Escribe un procedimiento C++ que aplique un procedimiento de ordenación que combine 
// las ideas de los métodos de ordenación por inserción y Quicksort de la forma siguiente: 
// en primer lugar se elige un pivote, entonces dos índices recorren la parte por ordenar 
// en sentidos ascendente descendente, respectivamente. Si el recorrido ascendente 
// encuentra un valor menor o igual que el pivote, lo inserta en orden por la izquierda 
// pero si encuentra un valor mayor que el pivote se detiene. 
// Si el recorrido descendente encuentra un valor mayor o igual que el pivote, 
// lo inserta por la derecha pero si encuentra un valor menor que el pivote se detiene. 
// Cuando ambos recorridos se detienen, se intercambian los elementos donde se han 
// parado que se insertan en la parte correspondiente y se continúa el proceso 
// hasta que ambos recorridos se encuentren. 
void Sort(int *sec, int N) {
  int ini, fin, piv, j, tmp;
    
  //Quicksort
  ini = 0;
  fin = N - 1;
  piv = sec[(ini + fin)/2];
  while (ini <= fin) {
      while (sec[ini] <= piv) { //si el valor es menor o igual se inserta por la izq
        tmp = sec[ini];
        j = ini;
        while((tmp < sec[j - 1]) && (j > 0)) {
          sec[j] = sec[j - 1];
          j--;  
        }
        sec[j] = tmp;
        ini++;
      }
      while (sec[fin] >= piv) {
        tmp = sec[fin];
        j = fin;
        while((tmp > sec[j + 1]) && (j < N)) {
          sec[j] = sec[j + 1];
          j++;  
        }
        sec[j] = tmp;
        fin--;
      }
      if (ini <= fin) {
          tmp = sec[ini];
          sec[ini] = sec[fin];
          sec[fin] = tmp;
      }
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