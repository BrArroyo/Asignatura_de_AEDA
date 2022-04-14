/**
 * @file main.cc
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Programa que utilizando una macro muestra el valor de una variable 
 * introducida por el usuario es par o impar.
 * 
 * @version 1.0
 * @date 2022-04-13  
 */


#include <iostream>

#define MACRO(num, str)      \
  {                          \
    std::cout << num;        \
    std::cout << " Es";      \
    std::cout << " " << str; \
    std::cout << "\n";       \
  }

/**
 * @brief Parte main del programa
 * 
 * @return int 
 */
int main() {  
  int num;
  std::cout << "introduce un número: ";
  std::cin >> num;
  if (num & 1) {  // (num % 2) == 1
    MACRO(num, "Impar");
  } else {
    MACRO(num, "Par");
  }

  return 0;
}