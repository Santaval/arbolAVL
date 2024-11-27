// Copyright 2024 algoritmicos team. ECCI-UCR. CC BY 4.0
#include "MatrixGraph.hpp"
#include <iostream>

void MatrixGraph::clear() {
  // Free the memory allocated for the matrix
  for (int i = 0; i < this->amount_vertex(); i++) {
    delete[] this->matrix[i];
  }
  delete[] this->matrix;
  // Clear the elements vector
  this->elements.clear();
}

void MatrixGraph::append_vertex(char element) {
  // Allocate memory for the new matrix
  this->increaseMatrixSize();
  // Update the matrix and elements
  this->elements.push_back(element);
  this->size++;
}



void MatrixGraph::delete_vertex(Vertex vertex) {
  this->decreaseMatrixSize();
  this->size--;
  this->elements.erase(this->elements.begin() + vertex);
}

void MatrixGraph::modify_element(Vertex vertex, char newElement) {
  this->elements[vertex] = newElement;
}

char MatrixGraph::element(Vertex vertex) {
  return this->elements[vertex];
}

void MatrixGraph::add_edge(Vertex vertex1, Vertex vertex2, double weight) {
  this->matrix[vertex1][vertex2] = weight;
}

void MatrixGraph::delete_edge(Vertex vertex1, Vertex vertex2) {
  this->matrix[vertex1][vertex2] = -1;
}

void MatrixGraph::modify_weight(Vertex vertex1, Vertex vertex2,
    double newWeight) {
  this->matrix[vertex1][vertex2] = newWeight;
}

double MatrixGraph::weight(Vertex vertex1, Vertex vertex2) {
  return this->matrix[vertex1][vertex2];
}

Vertex MatrixGraph::first_vertex() {
  if (this->amount_vertex() == 0) {
    return Vertex();
  } else {
    return Vertex(0);
  }
}

Vertex MatrixGraph::next_vertex(Vertex vertex) {
  if (vertex == this->amount_vertex() - 1) {
    return Vertex();
  } else {
    return Vertex(vertex + 1);
  }
}

Vertex MatrixGraph::first_adyacent_vertex(Vertex vertex) {
  for (int i = 0; i < this->amount_vertex(); i++) {
    if (this->matrix[vertex][i] != -1) {
      // return i;
    }
  }
  return Vertex();
}

Vertex MatrixGraph::next_adyacent_vertex(Vertex vertex, Vertex ady_vertex) {
  for (int i = ady_vertex + 1; i < this->amount_vertex(); i++) {
    if (this->matrix[vertex][i] != -1) {
      // return i;
    }
  }
  return Vertex();
}

void MatrixGraph::increaseMatrixSize() {
  // Allocate memory for the new matrix
  int newSize = this->amount_vertex() + 1;
  double** newMatrix = new double*[newSize];

  for (int i = 0; i < newSize; i++) {
    newMatrix[i] = new double[newSize];
  }

  // Copy the old matrix into the new matrix
  this->copyMatrix(newMatrix, this->matrix, this->amount_vertex());

  // Initialize the new row and column
  for (int i = 0; i < newSize; i++) {
    newMatrix[i][newSize - 1] = -1;
    newMatrix[newSize - 1][i] = -1;
  }

  this->deleteMatrix();
  this->matrix = newMatrix;
}

void MatrixGraph::decreaseMatrixSize() {
  // Allocate memory for the new matrix
  int newSize = this->amount_vertex() - 1;
  double** newMatrix = new double*[newSize];

  for (int i = 0; i < newSize; i++) {
    newMatrix[i] = new double[newSize];
  }

  // Copy the old matrix into the new matrix
  this->copyMatrix(newMatrix, this->matrix, newSize);

  this->deleteMatrix();
  this->matrix = newMatrix;
}

void MatrixGraph::copyMatrix(double** newMatrix, double** oldMatrix, int size) {
  // Copy the old matrix into the new matrix
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      newMatrix[i][j] = oldMatrix[i][j];
    }
  }
}

void MatrixGraph::deleteMatrix() {
  // Free the memory allocated for the matrix
  for (int i = 0; i < size; i++) {
    delete[] this->matrix[i];
  }
  delete[] this->matrix;
}
