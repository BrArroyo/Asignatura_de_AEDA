/**
 * Archivo sort_algorithm.cc: Archivo con las funciones plantillas de ordenación.
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzados
 * Curso: 2º
 * Práctica 05: Implementación de métodos de Ordenación
 *
 * @author Bruno Lorenzo Arroyo Pedraza
 * @email alu0101123677@ull.edu.es
 * @date 20/04/2022 
 * 
 * @brief Implementación de las plantillas de función
 * 
 * Historial de versiones:
 *   20/04/2022 - Ver 0.2 Incorporación de las plantillas de función
 *   21/04/2022 - Ver 1.0 Programa terminado
 */

#include <iostream>

/**
 * @brief Plantilla de función con el método de la ordenación por selección
 * 
 * @tparam Key 
 * @param sec Secuencia de valores
 * @param size Tamaño de la secuencia
 */
template <typename Key>
void selection_sort(Key *sec, int size) {
  Key x;
  for (int i = 0; i < size - 1; ++i) {
    int min = i;
    for (int j = i + 1; j < size; ++j) {
      if (sec[j] < sec[min]) {
        min = j;  
      }
      x = sec[min];
    }
    sec[min] = sec[i];
    sec[i] = x;
    #ifdef DEBUG
    std::cout << "\n" << i + 1 << " iteración: ";
    for (int j = 0; j < size; ++j) {
      std::cout << sec[j] << " ";
    }
    #endif 
  }
}

/**
 * @brief Plantilla de función auxiliar para hacer el método quicksort
 * 
 * @tparam Key 
 * @param sec Secuencia de valores
 * @param size Tamaño total de la secuencia entera
 * @param ini Inicio de secuencia
 * @param fin Final de secuencia
 */
template <typename Key>
void aux_quick_sort(Key *sec, int ini, int fin) {
  int i = ini;
  int f = fin;
  Key p = sec[(i + f)/2];
  while (i <= f) {
    while (sec[i] < p) {
      ++i;
    }
    while (sec[f] > p) {
      --f;
    }
    if (i <= f) {
      Key aux = sec[i];
      sec[i] = sec[f];
      sec[f] = aux; 
      ++i;
      --f;
      #ifdef DEBUG
      for (int j = 0; j < fin; ++j) {
        std::cout << sec[j] << " ";
      }
      std::cout << std::endl;
      #endif 
    }
  }

  if (ini < f) {
    aux_quick_sort(sec, ini, f);  
  }
  if (i < fin) {
    aux_quick_sort(sec, i, fin);
  }
}

/**
 * @brief Plantilla de función con el método de la ordenación por quicksort
 * 
 * @tparam Key 
 * @param sec Secuencia de valores
 * @param size Tamaño de la secuencia
 */
template <typename Key>
void quick_sort(Key *sec, int size) {
  int ini = 0;
  int fin = size - 1;
  aux_quick_sort(sec, ini, fin);   
}

/**
 * @brief Plantilla de función auxiliar para hacer el método shellsort
 * 
 * @tparam Key 
 * @param delta Valor delta
 * @param sec Secuencia de valores
 * @param size Tamaño de la secuencia
 */
template <typename Key>
void aux_shell_sort(int delta, Key *sec, int size) {
  for (int i = delta; i < size; ++i) {
    Key x = sec[i];
    int j = i;
    while ((j >= delta) && (x < sec[j - delta])) {
      sec[j] = sec[j - delta];
      j = j - delta;
    }
    sec[j] = x;  
  }
}

/**
 * @brief Plantilla de función con el método de la ordenación por shellsort
 * 
 * @tparam Key 
 * @param sec Secuencia de valores
 * @param size Tamaño de la secuencia
 */
template <typename Key>
void shell_sort(Key *sec, int size) {
  int delta = size;
  int iteration = 0;
  double alfa = 0.0;
  std::cout << "Que valor de alfa quieres(valor entre 0 y 1): ";
  std::cin >> alfa;
  while (alfa < 0.0 || alfa > 1.0) {
    if (alfa < 0.0 || alfa > 1.0) {
      std::cout << "Valor no posible, utilice otro valor: ";
      std::cin >> alfa; 
    } 
  }  
  while (delta > 1) {
    delta = delta * alfa;
    aux_shell_sort(delta, sec, size);
    #ifdef DEBUG
    std::cout << "\n" << iteration << " iteración: ";
    for (int j = 0; j < size; ++j) {
      std::cout << sec[j] << " ";
    }
    ++iteration;
    #endif   
  }
  
  delta = 1;
  aux_shell_sort(delta, sec, size);
  #ifdef DEBUG
  std::cout << "\n" << iteration << " iteración: ";
  for (int j = 0; j < size; ++j) {
    std::cout << sec[j] << " ";
  }
  ++iteration;
  #endif  
}

/**
 * @brief Plantilla función para el método down del heapsort
 * 
 * @tparam Key 
 * @param i 
 * @param sec Secuencia de valores
 * @param size Tamaño de la secuencia
 */
template <typename Key>
void down(int i, Key *sec, int size) {
  int h = i;
  int h1 = 2 * i + 1;
  int h2 = h1 + 1;

  if (h1 < size && sec[h1] > sec[h]) {
    h = h1;
  } 
  if (h2 < size && sec[h2] > sec[h]) {
    h = h2;
  }
  
  if (h != i) {
    Key aux = sec[i];
    sec[i] = sec[h];
    sec[h] = aux;
    down(h, sec, size);   
  }      
}

/**
 * @brief Plantilla de función con el método de la ordenación por heapsort
 * 
 * @tparam Key 
 * @param sec Secuencia de valores
 * @param size Tamaño de la secuencia
 */
template <typename Key>
void heap_sort(Key *sec, int size) {
  for (int i = size/2 - 1; i >= 0; --i) {
    down(i, sec, size);
  }
  int j = 0;
  for (int i = size - 1; i > 0; --i) {
    Key aux = sec[0];
    sec[0] = sec[i];
    sec[i] = aux;
    down(0, sec, i);
    #ifdef DEBUG
    std::cout << "\n" << ++j << " iteración: ";
    for (int j = 0; j < size; ++j) {
      std::cout << sec[j] << " ";
    }
    #endif 
  }
}

/**
 * @brief Devuelve el valor máximo de la secuencia
 * 
 * @tparam Key 
 * @param sec Secuencia de valores
 * @param size Tamaño de la secuencia
 * @return Key 
 */
template <typename Key>
Key getMax(Key *sec, int size) {
  Key max = sec[0];
  for (int i = 1; i < size; ++i) {
    if (sec[i] > max) {
      max = sec[i];
    }
  }
  return max;
}

/**
 * @brief Plantilla de función auxiliar RadixSort
 * 
 * @tparam Key 
 * @param sec Secuencia de valores
 * @param size Tamaño de valores
 * @param exp 
 */
template <typename Key>
void countSort(Key *sec, int size, int exp) {
  int output[size];
  int i, count[10] = {0};

  for (i = 0; i < size; ++i) {
    count[(sec[i] / exp) % 10]++;
  }
  
  for (i = 1; i < 10; ++i) {
   count[i] += count[i - 1];  
  }

  for (i = size - 1; i >= 0; --i) {
    output[count[(sec[i] / exp) % 10] - 1] = sec[i];
    count[(sec[i] / exp) % 10]--;
  }

  for (i = 0; i < size; ++i) {
    sec[i] = output[i];
  }
}

/**
 * @brief Plantilla de función con el método de la ordenación por radixsort
 * 
 * @tparam Key 
 * @param sec Secuencia de valores
 * @param size Tamaño de la secuencia
 */
template <typename Key>
void radix_sort(Key *sec, int size) {
  Key max = getMax(sec, size);
  int j = 0;
  for (int exp = 1; max/exp > 0; exp *= 10) {
    countSort(sec, size, exp);
    #ifdef DEBUG
    std::cout << "\n" << ++j << " iteración: ";
    for (int j = 0; j < size; ++j) {
      std::cout << sec[j] << " ";
    }
    #endif 
  } 
}