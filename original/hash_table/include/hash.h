// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructuras Datos Avanzada
// Curso: 2º
// Práctica 4: Tabla Hash
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 08/03/2024

#ifndef HASH_H_
#define HASH_H_

#include <iostream>
#include <vector>
#include <string>

#include "dispersion.h"
#include "exploration.h"

template <class Key>
class Sequence {
 public:
  virtual bool Search(const Key& key) const = 0;
  virtual bool Insert(const Key& key) = 0;
  virtual bool IsFull() const = 0;
};


template <class Key>
class StaticSequence : public Sequence<Key> {
 public:
  StaticSequence(const int& size);
  ~StaticSequence();
  bool Search(const Key& key) const override;
  bool Insert(const Key& key) override;
  bool IsFull() const override;


 private:
  Key** container_;
  int size_;
  int index_ = 0;
};


template <class Key>
class DynamicSequence : public Sequence<Key> {
 public:
  DynamicSequence() {}
  bool Search(const Key& key) const override;
  bool Insert(const Key& key) override;
  
 private:
  std::vector<Key> container_;
};


template <class Key, class Container=StaticSequence<Key>>
class HashTable : public Sequence<Key> {
 public:
  HashTable(const int& table_size, DispersionFunction<Key>& dispersion_function,
  ExplorationFunction<Key>& exploration_function, const int& block_size);
  ~HashTable();
  bool Search(const Key& key) const override;
  bool Insert(const Key& key) override;
  bool IsFull() const override;

 private:
  unsigned table_size_;
  Container** table_;
  DispersionFunction<Key>& dispersion_function_;
  ExplorationFunction<Key>& exploration_function_;
  int block_size_;
};


template<class Key>
class HashTable<Key, DynamicSequence<Key>> : public Sequence<Key> {
 public: 
  HashTable(const unsigned& table_size, DispersionFunction<Key>& dispersion_function);
  ~HashTable();
  bool Search(const Key& key) const override;
  bool Insert(const Key& key) override;
  bool IsFull() const override;

 private:
  unsigned table_size_;
  DynamicSequence<Key>** table_;
  DispersionFunction<Key>& dispersion_function_;
};


struct Parameters {
  unsigned table_size;
  std::string dispersion_function;
  std::string container;
  unsigned block_size;
  std::string exploration_function;
};

Parameters ReadParameters(int argc, char* argv[]);



#endif
