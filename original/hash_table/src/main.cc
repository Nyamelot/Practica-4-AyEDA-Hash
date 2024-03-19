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

#include "hash.h"
#include "dispersion.h"
#include "exploration.h"
#include "nif.h"

int main(int argc, char* argv[]) {
  ModuleDispersion<int> dispersion_1(2);
  DispersionFunction<int>* dispersion;
  dispersion = new ModuleDispersion<int>(5);
  ExplorationFunction<int>* exploration;
  exploration = new LinealExploration<int>(5);
  int table_size = 5;
  int block_size = 5;
  HashTable<int, DynamicSequence<int>> si(table_size, *dispersion);
  return 0;
}
