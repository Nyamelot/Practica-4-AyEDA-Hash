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
#include <vector>

#include "hash.h"

template<class Key>
StaticSequence<Key>::StaticSequence(const int& size) {
  size_ = size;
  container_ = new Key*[size_];
}


template<class Key>
StaticSequence<Key>::~StaticSequence() {
  delete[] container_;
}

template<class Key>
bool StaticSequence<Key>::Search(const Key& key) {
  for (int i = 0; i < size_; i++) {
    if (key == container_[i]) {
      return true;
    }
  }
  return false;
}


template<class Key>
bool StaticSequence<Key>::IsFull() {
  return index_ >= size_ ? true : false;
}


template<class Key>
bool StaticSequence<Key>::Insert(const Key& key) {
  if (IsFull(key)) {
    return false;
  } else {
    container_[index_] = key;
    index_++;
    return true;
  }
}


template<class Key>
bool DynamicSequence<Key>::Search(const Key& key) {
  for (const auto& value : container_) {
    if (key == value) {
      return true;
    }
  }
  return false;
}


template<class Key>
void DynamicSequence<Key>::Insert(const Key& key) {
  container_.emplace_back(key);
}


template<class Key, class Container>
HashTable<Key, Container>::HashTable(const int& table_size, const DispersionFunction<Key>& dispersion_function,
  const ExplorationFunction<Key>& exploration_function, const int& block_size) {
  table_size_ = table_size;
  table_ = new Container*[table_size_];
  dispersion_function_ = dispersion_function;
  exploration_function_ = exploration_function;
  block_size_ = block_size;
  for (int i = 0; i < table_size_; i++) {
    table_ = new Container(block_size_);
  }
}


template<class Key, class Container>
HashTable<Key, Container>::~HashTable() {
  for (int i = 0; i < table_size_; i++) {
    delete[] table_[i];
  }
  delete[] table_;
}


template<class Key, class Container>
bool HashTable<Key, Container>::Search(const Key& key) {
  int table_index = dispersion_function_(key);
  if (table_[table_index]->Search(key)) {
    return true;
  } else {
    if (!table_[table_index]->IsFull()) {
      return false;
    }
    int i = 1;
    while (true) {
      int exploration = exploration_function_(key, i);
      int new_index = exploration + table_index;
      new_index = new_index % table_size_;
      if (table_[new_index]->Search(key)) {
        return true;
      }
      if (new_index == table_size_) {
        break;
      }
      i++;
    }
    return false;
  }
}


template<class Key, class Container>
bool HashTable<Key, Container>::Insert(const Key& key) {
  int table_index = dispersion_function_(key);
  if (!table_[table_index]->IsFull()) {
    table_[table_index]->Insert(key);
    return true;
  } else {
    int i = 1;
    while (true) {
      int exploration = exploration_function_(key, i);
      int new_index = exploration + table_index;
      new_index = new_index % table_size_;
      if (table_[new_index]->Insert(key)) {
        return true;
      }
      if (new_index == table_size_) {
        break;
      }
      i++;
    }
    return false;
  }
}


template<class Key, class Container>
bool HashTable<Key, Container>::IsFull() {
  int counter = 0;
  for (int i = 0; i < table_size_; i++) {
    if (table_[i]->IsFull()) {
      counter++;
    }
  }
  return counter == table_size_ ? true : false;
}
