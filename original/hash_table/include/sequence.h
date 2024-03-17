// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructuras Datos Avanzada
// Curso: 2º
// Práctica 4: Tabla Hash
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 08/03/2024

#ifndef SEQUENCE_H_
#define SEQUENCE_H_

#include <iostream>
#include <vector>

template <class Key>
class Sequence {
 public:
  virtual bool Search(const Key& key) const = 0;
  virtual bool Insert(const Key& key) const = 0;
};


template <class Key>
class StaticSequence : public Sequence<Key> {
 public:
  StaticSequence(const int& size);
  ~StaticSequence();
  bool Search(const Key& key) override;
  bool Insert(const Key& key) override;

 private:
  Key* container_;
};


template <class Key>
class DynamicSequence : public Sequence<Key> {
 public:
  DynamicSequence() {}
  bool Search(const Key& key) override;
  bool Insert(const Key& key) override;

 private:
  std::vector<Key> container_;
};

#endif
