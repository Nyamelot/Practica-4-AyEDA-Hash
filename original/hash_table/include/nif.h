// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructuras Datos Avanzada
// Curso: 2º
// Práctica 4: Tabla Hash
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 08/03/2024

#ifndef NIF_H_
#define NIF_H_

#include <iostream>

class NIF {
 public:
  NIF();
  NIF(long num) : identification_(num) {}

  bool operator==(const NIF& nif) const;
  bool operator==(unsigned) const;
  inline int const GetID() const { return identification_; } 
  operator long() const;

 private:
 long identification_;
};

#endif
