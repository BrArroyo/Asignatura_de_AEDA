#include <iostream>
#include <fstream>


// x < sec[j - 1]) Menor --> Mayor  || x > sec[j - 1]) Mayor --> Menor
void Insercion(int *sec, int N) {
  int j, x;
  for (int i = 1; i < N; ++i) {
    x = sec[i];
    j = i;
    while (( x < sec[j - 1]) && (j > 0)) {
      sec[j] = sec[j - 1];
      j--;
    }
    sec[j] = x;
  }   
}

// sec[j] < sec[min] Menor --> Mayor || sec[j] > sec[min] Mayor --> Menor
void Seleccion(int *sec, int N) {
  int min, x;
  for (int i = 0; i < N - 1; i++) {
    min = i;
    for (int j = i + 1; j <= N - 1; j++) {
      if (sec[j] < sec[min]) 
        min = j;
    }

    x = sec[min];
    sec[min] = sec[i];
    sec[i] = x;
  }
}

void Burbuja(int *sec, int N) {
  int aux;
  for (int i = 1; i < N; i++) {
    for (int j = N-1; j >= i; j--) { 
      if (sec[j] < sec[j-1]) {
          aux = sec[j];
          sec[j] = sec[j - 1];
          sec[j - 1] = aux;
      } 
   }
  }
}

void Sacudida(int *sec, int N) {
  int ini = 1; 
  int fin = N-1; 
  int cam = N;
  int aux;
  while (ini < fin) {
    for (int j = fin; j >= ini; j--) {
      if (sec[j] < sec[j-1]) {
        aux = sec[j];
        sec[j] = sec[j - 1];
        sec[j - 1] = aux;
        cam = j ;
      }
    }   
    ini = cam + 1 ;
    for (int j = ini; j <= fin; j++) {
      if (sec[j] < sec[j-1]) {
        aux = sec[j];
        sec[j] = sec[j - 1];
        sec[j - 1] = aux;
        cam = j;
      }
    }   
    fin = cam - 1 ;
  }
}


// Falta el heapsort

void QuickSort(int *sec, int ini, int fin) {
  int aux;
  int i = ini ; 
  int f = fin ;
  int p = sec[(i+f)/2] ;
  while (i <= f){
    while (sec[i] < p) i++ ;
    while (sec[f] > p) f-- ;
    if (i <= f) {
      aux = sec[f];
      sec[f] = sec[i];
      sec[i] = aux;
      i++ ; 
      f-- ;
    } ;
  } ;
  if (ini < f) QuickSort(sec, ini, f) ; 
  if (i < fin) QuickSort(sec, i, fin) ; 
}

// Hacer mergesort

void deltasort(int delta, int *sec, int n) {
  for (int i = delta; i < n; i++){
    int x = sec[i] ;
    int j = i ;
    while ((j >= delta) && (x < sec[j - delta])){
      sec[j] = sec[j - delta] ;
      j = j - delta ;
    } 
    sec[j] = x ;
  } 
}

void ShellSort(int *sec, int N) {
  int delta = N ;
  while (delta > 1){
    delta = delta / 2 ;
    deltasort(delta,sec, N) ;
  }
}

int main(int argc, char * argv[]) {  
  int vector[] = {44, 55, 7, 42, 16, 40, 94, 12};
  int size = 8;
  
  for (int i = 0; i < size; ++i) {
    std::cout << vector[i] << " ";
  }
  
  //Insercion(vector, size);
  //Seleccion(vector, size);
  //Burbuja(vector, size);
  //Sacudida(vector, size);
  //QuickSort(vector, 0, size - 1);
  ShellSort(vector, size);
  
  std::cout << std::endl;
  for (int i = 0; i < size; ++i) {
    std::cout << vector[i] << " ";
  }

  std::cout << std::endl;
  std::cout << "Programa Finalizado" << std::endl;
  return 0;
}
