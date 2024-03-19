// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructuras Datos Avanzada
// Curso: 2º
// Práctica 4: Tabla Hash
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 08/03/2024

#ifndef EXPLORATION_H_
#define EXPLORATION_H_

#include <iostream>

#include <dispersion.h>

template<class Key>
class ExplorationFunction {
 public:
  virtual unsigned operator() (const Key&, unsigned exploration_tries) const = 0;
};


template<class Key>
class LinealExploration : public ExplorationFunction<Key> {
 public:
  LinealExploration(int table_size) : table_size_(table_size) {}
  unsigned operator() (const Key&, unsigned exploration_tries) override;

 protected:
  int table_size_;
};


template<class Key>
class QuadraticExploration : public ExplorationFunction<Key> {
 public:
  QuadraticExploration(int table_size) : table_size_(table_size) {}
  unsigned operator() (const Key&, unsigned exploration_tries) override;

 protected:
  int table_size_;
};


template<class Key>
class DobleDispersionExploration : public ExplorationFunction<Key> {
 public:
  DobleDispersionExploration(int table_size, const DispersionFunction<Key>& dispersion_function) : 
  table_size_(table_size), dispersion_function_(dispersion_function) {}
  unsigned operator() (const Key&, unsigned exploration_tries) override;

 protected:
  int table_size_;
  DispersionFunction<Key> dispersion_function_;
};


template<class Key>
class RedispersionExploration : public ExplorationFunction<Key> {
 public:
  RedispersionExploration(int table_size) : table_size_(table_size) {}
  unsigned operator() (const Key&, unsigned exploration_tries) override;

 protected:
  int table_size_;
};

#endif
