// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructuras Datos Avanzada
// Curso: 2º
// Práctica 4: Tabla Hash
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 08/03/2024

#ifndef DISPERSION_FUNCTION_H_
#define DISPERSION_FUNCTION_H_

#include <iostream>

template<class Key>
class DispersionFunction {
 public:
  virtual unsigned operator() (const Key&) const = 0;
};


template<class Key>
class ModuleDispersion : public DispersionFunction<Key> {
 public:
  ModuleDispersion(int table_size) : table_size_(table_size) {}
  unsigned operator() (const Key&) override;

 protected:
  int table_size_;
};


template<class Key>
class SumDispersion : public DispersionFunction<Key> {
 public:
  SumDispersion(int table_size) : table_size_(table_size) {}
  unsigned operator() (const Key&) override;
 protected:
  int table_size_;
};


template<class Key>
class RandomDispersion : public DispersionFunction<Key> {
 public:
  RandomDispersion(int table_size) : table_size_(table_size) {}
  unsigned operator() (const Key&) override;
 protected:
  int table_size_;
};

#endif
