#include <iostream>
#include <fstream>

//-------------INSERCION---------------------
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
//--------------------------------------------

//-------------SELECCION---------------------
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
//--------------------------------------------

//-------------QuickSort-----------------------
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
//--------------------------------------------

//-------------BURBUJA-----------------------
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
//--------------------------------------------

//-------------SACUDIDA-----------------------
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
//--------------------------------------------

//-------------HEAPSORT-----------------------
void Baja(int i, int *sec, int n) {
  int h = i;
  int h1 = 2 * i + 1;
  int h2 = 2 * i + 2;

  if (h1 < n && sec[h1] > sec[h]) {
    h = h1;
  } 
  if (h2 < n && sec[h2] > sec[h]) {
    h = h2;
  }
  
  if (h != i) {
    int aux = sec[i];
    sec[i] = sec[h];
    sec[h] = aux;
    Baja(h, sec, n);   
  }  
}

void HeapSort(int *sec, int N) {
  for (int i = N/2 - 1; i >= 0; --i) {
    Baja(i, sec, N);
  }
  int j = 0;
  for (int i = N - 1; i > 0; --i) {
    int aux = sec[0];
    sec[0] = sec[i];
    sec[i] = aux;
    Baja(0, sec, i);
  }
}
//--------------------------------------------

//-------------RadixSort-----------------------
void CountSort(int *sec, int size, int exp) {
  int output[size];
  int i, count[10] = {0};

  for (i = 0; i < size; ++i) {
    count[(sec[i] / exp) % 10]++;
  }
  
  for (i = 1; i < 10; ++i) {
   count[i] += count[i - 1];  
  }

  for (i = size - 1; i >= 0; --i) {
    output[count[(sec[i] / exp) % 10] - 1] = sec[i];
    count[(sec[i] / exp) % 10]--;
  }

  for (i = 0; i < size; ++i) {
    sec[i] = output[i];
  }
}

void RadixSort(int *sec, int N) {
  int max = sec[0];
  for (int i = 1; i < N; i++) {
    if (sec[i] > max) max = sec[i];
  }

  for (int i = 1; max / i > 0; i *= 10)
    CountSort(sec, N, i);
}
//--------------------------------------------

//-------------MergeSort-----------------------
void Mezcla(int *sec, int ini, int cen, int fin) {
  int aux[ini + fin];
  int i = ini, j = cen + 1;
  for (int k = ini; k <= fin; k++) {
    if (i < cen && j > fin || sec[i] < sec[j]) {
      aux[k] = sec[i];
      i++;
    } else {
      aux[k] = sec[j];
      j++;
    }
  }
  for (int k = ini; k <= fin; k++)
    sec[k] = aux[k];
}

void MergeSort(int *sec, int ini, int fin) {
  if (ini < fin) {
    int cen = (ini + fin) / 2;
    MergeSort(sec, ini, cen);
    MergeSort(sec, cen + 1, fin);
    Mezcla (sec, ini, cen, fin);
  }
}
//--------------------------------------------

//-------------ShellSort-----------------------
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
//--------------------------------------------

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
  //ShellSort(vector, size);
  //HeapSort(vector, size);
  //RadixSort(vector, size);
  //MergeSort(vector, 0, size - 1);
  
  std::cout << std::endl;
  for (int i = 0; i < size; ++i) {
    std::cout << vector[i] << " ";
  }

  std::cout << std::endl;
  std::cout << "Programa Finalizado" << std::endl;
  return 0;
}
