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

#include "nif.h"

NIF::NIF() {
  srand(time(0));
  identification_ = rand() % 100000000;
}

bool NIF::operator==(const NIF& nif_2) const {
  return identification_ == nif_2.GetID();
}

NIF::operator long() const {
  return identification_;
}


bool NIF::operator==(unsigned num) const {
  return identification_ == num;
}


std::ostream& operator<<(std::ostream& os, const NIF& nif) {
  os << nif.GetID();
  return os;
}
