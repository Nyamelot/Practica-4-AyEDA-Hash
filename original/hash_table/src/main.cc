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
  Parameters parameters = ReadParameters(argc, argv);
  int table_size = parameters.table_size;
  int block_size = parameters.block_size;
  DispersionFunction<NIF>* dispersion;
  ExplorationFunction<NIF>* exploration;
  if (parameters.dispersion_function == "module") {
    dispersion = new ModuleDispersion<NIF>(table_size);
  }
  if (parameters.dispersion_function == "sum") {
    dispersion = new SumModuleDispersion<NIF>(tabla_size);
  }
  if (parameters.dispersion_function == "random") {
    dispersion = new RandomDispersion<NIF>;
  }
  if (parameters.exploration_function == "lineal") {
    exploration = new LinealExploration<NIF>;
  }
  if (parameters.exploration_function == "Quadratic") {
    exploration = new QuadraticExploration<NIF>;
  }
  // ModuleDispersion<int> dispersion_1(2);
  // DispersionFunction<int>* dispersion;
  // dispersion = new ModuleDispersion<int>(5);
  // ExplorationFunction<int>* exploration;
  // exploration = new LinealExploration<int>(5);
  // int table_size = 5;
  // int block_size = 5;
  // HashTable<int, DynamicSequence<int>> si(table_size, *dispersion);
  return 0;
}
