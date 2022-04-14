/**
 * @file main.cc
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Implementación de busqueda lineal doble 
 *  
 * @version 1.0
 * @date 2022-04-13  
 */

#include <iostream>

/**
 * @brief Método de búsqueda lineal doble
 * 
 * @param find 
 * @param v 
 * @param ini 
 * @param fin 
 * @return int 
 */
int BusSecDoble(int find, int v[], int ini, int fin){
  int med = (ini + fin) / 2;
  for (int pos = ini; pos <= med; pos++) {
    if (v[pos] == find) {
      std::cout << "posición " << pos;
      return pos;
    }  
    if (v[fin-pos] == find) {
      std::cout << "posición " << fin-pos;
      return fin-pos;
    }  
  }
  
  return -1;
}


/**
 * @brief Función main del programa
 * 
 * @return int 
 */
int main(int argc, char *argv[]) {
  int v[] = {2, 3, 7, 8, 9};
  int ini = 0;
  int fin = 4;
  int find = std::stoi(argv[1]);
  if (BusSecDoble(find, v, ini,fin) != -1) {
    std::cout << " se ha encontrado el elemento" << std::endl;
  } else {
    std::cout << "No se ha encontrado el elemento" << std::endl;
  }
  return 0;
}