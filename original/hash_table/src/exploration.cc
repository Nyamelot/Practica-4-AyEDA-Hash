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
#include <cmath>
#include <random>
#include <cstdlib>

#include "exploration.h"

template<class Key>
unsigned LinealExploration<Key>::operator() (const Key& key, unsigned exploration_tries) const {
  return exploration_tries;
}


template<class Key>
unsigned QuadraticExploration<Key>::operator() (const Key& key, unsigned exploration_tries) const {
  return static_cast<unsigned>(pow(exploration_tries, 2));
}


template<class Key>
unsigned DobleDispersionExploration<Key>::operator() (const Key& key, unsigned exploration_tries) const {
  return dispersion_function_(key) * exploration_tries;
}


template<class Key>
unsigned RedispersionExploration<Key>::operator() (const Key& key, unsigned exploration_tries) const {
  srand(key);
  unsigned result = 0;
  for (int i = 1; i <= exploration_tries; i++) {
    result = rand();
  }
  return result % table_size_;
}

template class LinealExploration<int>;
template class QuadraticExploration<int>;
template class DobleDispersionExploration<int>;
template class RedispersionExploration<int>;
