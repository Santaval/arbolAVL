// Copyright 2024 algoritmicos team. ECCI-UCR. CC BY 4.0
#pragma once
#include <functional>  // Para std::hash
#include <cstddef>     // Para size_t

#define NULL_VERTEX -1

class Vertex {
 public:
  int number;

 public:
  explicit Vertex(int number) : number(number) {}
  Vertex() : number(-1) {}
  ~Vertex();

  int operator++();
  int operator--();
  bool operator==(const Vertex &number);
  bool operator==(const int number);
  operator int() const;
};
