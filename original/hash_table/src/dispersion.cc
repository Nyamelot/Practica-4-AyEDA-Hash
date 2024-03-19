// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructuras Datos Avanzada
// Curso: 2º
// Práctica 4: Tabla Hash
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 08/03/2024

#include <iostream>
#include <random>
#include <cstdlib>

#include "dispersion.h"

template<class Key>
unsigned ModuleDispersion<Key>::operator() (const Key& key) const {
  return key % table_size_;
}


template<class Key>
unsigned SumDispersion<Key>::operator() (const Key& key) const {
  Key key_copy = key;
  int sum_digit = 0;
  while (key_copy > 0) {
    sum_digit = key_copy % 10;
    key_copy /= 10;
  }
  return sum_digit % table_size_;
}


template<class Key>
unsigned RandomDispersion<Key>::operator() (const Key& key) const {
  srand(key);
  return rand() % table_size_;
}

template class ModuleDispersion<int>;
template class SumDispersion<int>;
template class RandomDispersion<int>;
