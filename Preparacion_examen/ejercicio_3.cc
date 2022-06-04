#include <iostream>
#include <fstream>

// Escribe un procedimiento C++ que aplique el procedimiento de ordenación siguiente: 
// se aplica una iteración del método Quicksort para dividir la secuencia en dos partes 
// y se ordena, la primera parte por inserción y la segunda por selección.
void Sort(int *sec, int N) {
  int ini, fin, piv, min, j, tmp;
    
  //Quicksort
  ini = 0;
  fin = N - 1;
  piv = sec[(ini + fin)/2];
  while (ini <= fin) {
      while (sec[ini] < piv) ini++;
      while (sec[fin] > piv) fin--;
      if (ini <= fin) {
          tmp = sec[ini];
          sec[ini] = sec[fin];
          sec[fin] = tmp;
          ini++;
          fin--;
      }
  }
  std::cout << std::endl;
  std::cout << fin << " - " << ini << std::endl;
  std::cout << "Quicksort:       ";
  for(int i = 0; i < N; i++) {
      std::cout << sec[i] << " ";
  }
  std::cout << "\n";
  
 

  // Inserción [0 - fin]
  int x;
  for (int i = 1; i <= fin; ++i) {
    x = sec[i];
    j = i;
    while (( x < sec[j - 1]) && (j > 0)) {
      sec[j] = sec[j - 1];
      j--;
    }
    sec[j] = x;
  }   

  std::cout << "Insercicion:     ";
  for(int i = 0; i < N; i++) {
      std::cout << sec[i] << " ";
  }
  std::cout << "\n";

  // Selección [ini - (N-1)]
  for (int i = ini; i < N - 1; i++) {
    min = i;
    for (int j = i + 1; j <= N - 1; j++) {
      if (sec[j] < sec[min]) 
        min = j;
    }
    tmp = sec[min];
    sec[min] = sec[i];
    sec[i] = tmp;
  }

  std::cout << "Seleccion:       ";
  for(int i = 0; i < N; i++) {
      std::cout << sec[i] << " ";
  }
  std::cout << "\n";

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