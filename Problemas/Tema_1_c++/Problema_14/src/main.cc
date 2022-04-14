/**
 * @file main.cc
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Dada una expresión balanceada que puede contener paréntesis abiertos y 
 * cerrados, (), comprobar si contiene paréntesis duplicados.
 * 
 * @version 1.0
 * @date 2022-04-13  
 */

#include <iostream>
#include <stack>

/**
 * @brief Función para comprobar parentesis repetidos
 * 
 * @param expression 
 * @return true 
 * @return false 
 */
bool HasDuplicateParenthesis(std::string expression) {
  // take an empty stack of characters
  std::stack<char> stack;
  // traverse the input expression
  for (char character : expression) {
    std::cout << character << std::endl;
    // if the current char in the expression is not a closing parenthesis
    if (character != ')') {
      stack.push(character);
    }
    // if the current char in the expression is a closing parenthesis
    else {
      // if the stack's top element is an opening parenthesis, the subexpression of the form ((exp)) is found
      if (stack.top() == '(') {
        return true;
      }
      // pop till '(' is found for current ')'
      while (stack.top() != '(') {
        stack.pop();
      }
      // pop '('
      stack.pop();
    }
  }
  // if we reach here, then the expression does not have any duplicate parenthesis
  return false;
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
  if (HasDuplicateParenthesis(expression)) {
    std::cout << "La expresión '" << expression << "' tiene parentesis duplicados." << std::endl;
  } else {
    std::cout << "La expresión '" << expression << "' no tiene parentesis duplicados." << std::endl;
  }
  return 0;
}