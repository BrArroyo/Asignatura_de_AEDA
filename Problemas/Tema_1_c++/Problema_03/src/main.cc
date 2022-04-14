/**
 * @file main.cc
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Programa que calcula el tiempo requerido para calcular el factorial 
 * de un número mediante una función convencional y una inline.
 * 
 * @version 1.0
 * @date 2022-04-13  
 */


#include <chrono>
#include <iostream>

/**
 * @brief Método factorial 
 * 
 * @param n 
 * @return int 
 */
int Factorial(int n) {
  return (n < 2) ? 1 : n * Factorial(n - 1);
}

/**
 * @brief Método factorial inline
 * 
 * @param n 
 * @return int 
 */
inline int InlineFactorial(int n) {
  return (n < 2) ? 1 : n * InlineFactorial(n - 1);
}

/**
 * @brief Parte main del programa
 * 
 * @return int 
 */
int main(int argc, char* argv[]) {  
  if (argc != 2) {
    std::cout << "No se le ha pasado un valor" << std::endl;
    return 1;
  }

  std::string check = argv[1];
  for (char const &c : check) {
    if (std::isdigit(c) == 0) {
      std::cout << "No se le ha pasado un valor" << std::endl;
      return 1;
    }  
  }
  
  int value = std::stoi(argv[1]); 

  std::cout << "Midiendo tiempo mediante función convencional:" << std::endl;
  std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();
  Factorial(value);
  std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> elapsedTime = endTime - startTime;
  std::cout << "Tiempo: " << elapsedTime.count() << " ms.\n";

  std::cout << "Midiendo tiempo mediante función en línea:" << std::endl;
  std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
  InlineFactorial(value);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> elapsedTimeInline = end - start;
  std::cout << "Tiempo " << elapsedTimeInline.count() << " ms.\n";

  return 0;
}