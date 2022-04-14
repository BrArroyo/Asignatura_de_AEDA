/**
 * @file main.cc
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Dado un número n, generar números binarios entre 1 y n empleando una cola.
 * 
 * @version 1.0
 * @date 2022-04-13  
 */

#include <iostream>
#include <queue>
#include <string>


/**
 * @brief Función que genera números binarios
 * 
 * @param numbers 
 */
void BinaryNumbers(int numbers) {
  std::queue<std::string> queue;
  queue.push("1");
  int i = 1;
  while (i <= numbers) {
    // append 0 and 1 to the front element of the queue and enqueue both strings
    queue.push(queue.front() + "0");
    queue.push(queue.front() + "1");
    // dequeue front element after printing it
    std::cout << queue.front() << ' ';
    queue.pop();
    i++;
  }
}

/**
 * @brief Función main del programa
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[]) {
  const int kNumbers = std::stoi(argv[1]);
  BinaryNumbers(kNumbers);
  std::cout << std::endl;
  return 0;
}