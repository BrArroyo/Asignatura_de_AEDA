/**
 * @file main.cc
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Programa que comprueba si una expresión compuesta por 
 * corchetes, paréntesis y llaves está balanceada.
 * 
 * @version 1.0
 * @date 2022-04-13  
 */

#include <iostream>
#include <stack>
#include <string>

/**
 * @brief Función que comprueba si la expresión está balanceada
 * 
 * @param expression 
 * @return true 
 * @return false 
 */
bool AreBracketsBalanced(std::string expression) {
  std::stack<char> stack;
  char toCheck;
  for (int i = 0; i < expression.length(); i++) {
    char character = expression[i];
    if (character == '(' || character == '[' || character == '{') {
      stack.push(character);
    } else if (stack.empty()) {
      return false;
    } else {
      switch (character) {
        case ')':
          toCheck = stack.top();
          stack.pop();
          if (toCheck == '{' || toCheck == '[') {
            return false;
          }
          break;
        case '}':
          toCheck = stack.top();
          stack.pop();
          if (toCheck == '(' || toCheck == '[') {
            return false;
          }
          break;
        case ']':
          toCheck = stack.top();
          stack.pop();
          if (toCheck == '(' || toCheck == '{') {
            return false;
          }
          break;
      }
    }
  }
  return stack.empty();
}

/**
 * @brief Función main del programa
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[]) {
  const std::string expression = argv[1];

  if (AreBracketsBalanced(expression)) {
    std::cout << "La expresión '" << expression << "' Esta balanceada" << std::endl;
  } else {
    std::cout << "La expresión '" << expression << "' No esta balanceada" << std::endl;
  }

  return 0;
}