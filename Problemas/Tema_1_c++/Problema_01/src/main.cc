/**
 * @file main.cc
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Programa que cambia cada una de las letras presentes en una cadena de 
 * texto por la letra siguiente del alfabeto
 * 
 * @version 1.0
 * @date 2022-04-13  
 */

#include <iostream>

/**
 * @brief Función para cambiar las letras de una cadena por su siguiente letra
 * 
 * @param chain 
 * @return std::string 
 */
std::string NextLetter(const std::string& chain) {
  std::string result;

  for (int i = 0; i < chain.length(); ++i) {
    auto current_char = chain.at(i);
    if (isalpha(current_char)) {
      if ((current_char != 'z') && (current_char != 'Z')) {
        result.push_back(current_char + 1);
      }
    }
  }

  return result;
}

/**
 * @brief Parte main del programa
 * 
 * @return int 
 */
int main(int argc, char* argv[]) {  
  if (argc != 2) {
    std::cout << "No se le ha pasado una cadena" << std::endl;
    return 1;
  }
  
  std::string chain = argv[1];
  std::cout << "Resultado: " << NextLetter(chain) << std::endl;

  return 0;
}