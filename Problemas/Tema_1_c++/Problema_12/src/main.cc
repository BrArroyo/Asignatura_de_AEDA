/**
 * @file main.cc
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Programa que convierte una expresión dada en notación 
 * infija en notación postfija.
 * 
 * @version 1.0
 * @date 2022-04-13  
 */

#include <iostream>
#include <stack>
#include <string>

/**
 * @brief Función que calcula el precedente
 * 
 * @param character 
 * @return int 
 */
int Precedence(char character) {
  if (character == '^') {
    return 3;
  } else if (character == '/' || character == '*') {
    return 2;
  } else if (character == '+' || character == '-') {
    return 1;
  } else {
    return -1;
  }
}

/**
 * @brief Función que cambia de infija a postfija
 * 
 * @param expression 
 * @return std::string 
 */
std::string InfixToPostfix(std::string expression) {
  std::stack<char> stack;
  std::string result;
  for (int i = 0; i < expression.length(); i++) {
    char character = expression[i];
    if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z') || (character >= '0' && character <= '9')) {
      result += character;
    } else if (character == '(') {
      stack.push('(');
    } else if (character == ')') {
      while (stack.top() != '(') {
        result += stack.top();
        stack.pop();
      }
      stack.pop();
    } else {
      while (!stack.empty() && Precedence(expression[i]) <= Precedence(stack.top())) {
        result += stack.top();
        stack.pop();
      }
      stack.push(character);
    }
  }
  while (!stack.empty()) {
    result += stack.top();
    stack.pop();
  }
  return result;
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
  std::string postfix_expression = InfixToPostfix(expression);
  std::cout << postfix_expression << std::endl;
  return 0;
}