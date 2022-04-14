/**
 * @file main.cc
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Implementación de busqueda binaria con elementos repetidos
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
bool BusBinariaRep(int find, int v[], int ini, int fin){
    int pos = ini;
    while (ini < fin) {
      pos = (ini + fin) / 2;
      if (v[pos] < find) {
        ini = pos + 1;
      } else {
        fin = pos;
      }  
    }

    if (v[ini] == find) {
      int primero = ini;
      while (v[primero] == find)
        primero--;
      primero ++;
      int ultimo = ini;
      while (v[ultimo] == find)
        ultimo++;
      ultimo--;
      std::cout << "Posición " << ultimo << " ";
      return true;
    } else {
      return false;
    }  
}

/**
 * @brief Función main del programa
 * 
 * @return int 
 */
int main(int argc, char *argv[]) {
  int v[] = {2, 3, 7, 9, 10};
  int ini = 0;
  int fin = 4;
  int find = std::stoi(argv[1]);
  if (BusBinariaRep(find, v, ini,fin)) {
    std::cout << "se ha encontrado el elemento" << std::endl;
  } else {
    std::cout << "No se ha encontrado el elemento" << std::endl;
  }
  return 0;
}
