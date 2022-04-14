/**
 * @file main.cc
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Implementación de busqueda binaria con del valor máspróximo a un entero dado como
 * parámetro
 * 
 * @version 1.0
 * @date 2022-04-13  
 */

#include <iostream>

/**
 * @brief Método de búsqueda binaria
 * 
 * @param find 
 * @param v 
 * @param ini 
 * @param fin 
 * @return int 
 */
bool BusBinaria2(int find, int v[], int ini, int fin) {
  int med = (ini + fin) / 2;
  int pos = ini; 
  int fin2 = med;

  while (ini < fin2) {
    pos = (ini + fin2) / 2;
    if (v[pos] < find) {
      ini = pos + 1;
    } else {
      fin = pos;
    }      
  }
  if (v[ini] == find) {
    std::cout << "posición " << ini;
    return true;
  } else {
    ini = med + 1;
    med = (ini + fin) / 2;
    pos = ini;
    while (ini < fin) {
      pos = (ini + fin) / 2;
      if (v[pos] < find) {
        ini = pos + 1;
      } else {
        fin = pos;
      }                
    }
    if (v[ini] == find) {
      std::cout << "posición " << ini;
      return true;
    } else {
      return false;
    } 
  }
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
  if (BusBinaria2(find, v, ini,fin)) {
    std::cout << " se ha encontrado el elemento" << std::endl;
  } else {
    std::cout << "No se ha encontrado el elemento" << std::endl;
  }
  return 0;
}