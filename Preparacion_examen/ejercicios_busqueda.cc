#include <iostream>

// Suponga que un vector ordenado de mayor a menor puede tener elementos repetidos. 
// Implemente un algoritmo que usando la búsqueda binaria muestre todas las posiciones 
// en las que se encuentra un determinado valor, si está.
void Binary_Search(int x, int v[], int ini, int fin) {
  int pos = ini;
  while (ini < fin) {
    pos = (ini + fin) / 2;
    if (v[pos] > x) ini = pos + 1;
    else fin = pos;
  }
  if (v[pos] == x) {
    int first = ini, last = fin;
    while (v[first] == x) first--;
    while (v[last] == x) last++;
    first++;
    last--;
    if(first == last) std::cout << "El elemento se encuentra en la posición " << first << std::endl;
    else std::cout << "El elemento está repetido y está entre las posiciones " << first << " - " << last << std::endl;
  }
}

// Se sabe que un vector de números de tipo int está ordenado de menor a mayor hasta 
// la mitad y de mayor a menor desde la mitad hasta el final. 
// Implemente un algoritmo que usando la búsqueda binaria encuentre la posición del 
// valor más próximo a un entero dado como parámetro.
void Binary_Search_2(int x, int v[], int ini, int fin) {
  int pos, fin_aux;
  int mitad = (ini + fin) / 2;
  fin_aux = mitad;
  while (ini < fin_aux) { //Menor a mayor desde 0 hasta mitad
    pos = (ini + fin_aux) / 2;
    if (v[pos] < x) ini = pos + 1;
    else fin_aux = pos;
  }
  if (v[ini] == x) std::cout << "El elemento se encuentra en " << ini << std::endl;
  else {
    ini = mitad + 1;
    while (ini < fin) { //Mayor a menor desde mitad + 1 hasta fin
      pos = (ini + fin) / 2;
      if (v[pos] > x) ini = pos + 1;
      else fin = pos;
    }
    if (v[ini] == x) std::cout << "El elemento se encuentra en " << ini << std::endl;   
  }
}

// Se sospecha que los elementos más buscados de una secuencia están al principio o 
// al final de la secuencia. Implemente una búsqueda lineal desde ambos extremos.
void Lineal_search(int x, int v[], int ini, int fin) {
  for (int i = 0; i <= (ini + fin) / 2 ; ++i) {
    if(v[i] == x) std::cout << "Está en la posición: " << i << std::endl;
    if(v[fin - i] == x) std::cout << "Está en la posición: " << fin - i << std::endl;
  }
}

int main(int argc, char * argv[]) {  
  int vector_binario[] = {90, 60, 55, 42, 38, 38, 12, 7};
  int vector_binario_2[] = {7, 8, 50, 55, 67, 40, 30, 10};
  int vector_lineal[] = {44, 55, 7, 42, 16, 40, 94, 12};
  
  int size = 8;

  Binary_Search(38, vector_binario, 0, size - 1);
  Binary_Search_2(50, vector_binario_2, 0 ,size - 1);
  Lineal_search(12, vector_lineal, 0, size - 1);

  std::cout << std::endl;
  std::cout << "Programa Finalizado" << std::endl;
  return 0;
}
