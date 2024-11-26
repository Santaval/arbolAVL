// Copyright 2024 algoritmicos team. ECCI-UCR. CC BY 4.0
#include "Vertex.hpp"

int Vertex::operator++() {
  return this->number++;
}

int Vertex::operator--() {
  return this->number--;
}

bool Vertex::operator==(const Vertex &vertex) {
  return this->number == vertex.number;
}

bool Vertex::operator==(const int number) {
  return this->number == number;
}

Vertex::operator int() const {
  return this->number;
}

Vertex::~Vertex() {
  this->number = 0;
}
