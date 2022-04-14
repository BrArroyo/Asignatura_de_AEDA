/**
 * @file disjoint.cc
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Definición de los métodos de DisjointSet
 * 
 * @version 1.0
 * @date 2022-04-13  
 */

#include "../include/disjoint.h"

DisjointSet::DisjointSet(int size) {
  rank = new int[size];
  parent = new int[size];
  this->size_ = size;
  for (int i = 0; i < size_; i++) {
    parent[i] = i;
    rank[i] = 0;
  }
}

/**
 * @brief Función para encontrar un elemento
 * 
 * @param toFind 
 * @return int 
 */
int DisjointSet::find(int toFind) {
  if (parent[toFind] != toFind) {
    parent[toFind] = find(parent[toFind]);
  }
  return parent[toFind];
}

/**
 * @brief Función para unir dos elementos
 * 
 * @param x 
 * @param y 
 */
// Do union of two sets represented by x and y.
void DisjointSet::Union(int x, int y) {
  int xset = find(x);
  int yset = find(y);
  if (xset == yset) {
    return;
  }
  // Put smaller ranked item under bigger ranked item if ranks are different
  if (rank[xset] < rank[yset]) {
    parent[xset] = yset;
  } else if (rank[xset] > rank[yset]) {
    parent[yset] = xset;
  }
  // If ranks are same, then increment rank.
  else {
    parent[yset] = xset;
    rank[xset] = rank[xset] + 1;
  }
}