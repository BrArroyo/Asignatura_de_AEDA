/**
 * @file main.cc
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Programa que solicite al usuario una cantidad de números y calcule su media.
 * 
 * @version 1.0
 * @date 2022-04-13  
 */


#include <iostream>

/**
 * @brief Función para calcular la medía 
 * 
 * @param amount 
 * @return double 
 */
double Average(int amount) {
  double average = 0.0;
  double entry = 0.0;
  std::cout << "Introduce 5 elementos" << std::endl;

  for (int i = 0; i < amount; ++i) {
    std::cout << "Elemento " << i + 1 << ": ";
    std::cin >> entry;
    average = average + entry; 
  }
 
  return average/amount;
}

/**
 * @brief Parte main del programa
 * 
 * @return int 
 */
int main(int argc, char* argv[]) {  
  if (argc != 2) {
    std::cout << "No se le ha pasado una cantidad de valores" << std::endl;
    return 1;
  }

  std::string amount = argv[1];
  for (char const &c : amount) {
    if (std::isdigit(c) == 0) {
      std::cout << "No se le ha pasado una cantidad de valores" << std::endl;
      return 1;
    }  
  }
  
  int number_of_elements = std::stoi(argv[1]); 
  double result =  Average(number_of_elements);
  std::cout << "Media: " << result << std::endl;

  return 0;
}