/**
 * @file disjoint.h
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Clase que implementa un conjunto disjunto
 * 
 * @version 1.0
 * @date 2022-04-13  
 */

/**
 * @class DisjointSet
 * @brief Clase que implementa un conjunto disjunto
 * 
 */
class DisjointSet {
 public:
  DisjointSet(int size);
  int find(int x);
  void Union(int x, int y);

 private:
  int *rank;
  int *parent;
  int size_;
};