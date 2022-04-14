/**
 * @file pair.h
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Clase que representa un par
 * 
 * @version 1.0
 * @date 2022-04-13  
 */

#ifndef PAIR_H_
#define PAIR_H_

/**
 * @class Pair
 * @brief Clase que representa un par
 * 
 * @tparam T 
 */
template <class T>
class Pair {
 public:
  Pair() {}
  Pair(T first, T second) {
    element1_ = first;
    element2_ = second;
  }
  T GetMax();
  template <class U>
  friend std::ostream& operator<<(std::ostream& out, const Pair<U>& pair);

 private:
  T element1_;
  T element2_;
};

/**
 * @brief Sobrecarga del operador <<
 * 
 * @tparam T 
 * @param out 
 * @param pair 
 * @return std::ostream& 
 */
template <class T>
std::ostream& operator<<(std::ostream& out, const Pair<T>& pair) {
  out << "{" << pair.element1_ << "," << pair.element2_ << "}";
  return out;
}

#endif