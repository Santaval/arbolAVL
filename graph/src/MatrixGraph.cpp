#pragma once

#include "MatrixGraph.hpp"
#include <iostream>

void MatrixGraph::clear() {
    this->matrix.clear();
    this->elements.clear();
    this->size = 0;
}

void MatrixGraph::append_vertex(char element) {
    this->elements.push_back(element);
    const int newSize = this->amount_vertex() + 1;
    this->matrix.push_back(std::vector<double>(newSize, -1));
    this->add_cols_field();
    this->size++;
}

void MatrixGraph::add_cols_field() {
    for (int i = 0; i < this->amount_vertex(); i++) {
        this->matrix[i].push_back(-1);
    }
 }


void MatrixGraph::remove_cols_field(int index) {
    for (int i = 0; i < this->amount_vertex(); i++) {
        this->matrix[i].erase(this->matrix[i].begin() + index);
    }
}

void MatrixGraph::delete_vertex(Vertex vertex) {
    this->elements.erase(this->elements.begin() + vertex);
    this->remove_cols_field(vertex);
    this->elements.erase(this->elements.begin() + vertex);
    this->size--;
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

void MatrixGraph::modify_weight(Vertex vertex1, Vertex vertex2, double newWeight) {
    this->matrix[vertex1][vertex2] = newWeight;
}

double MatrixGraph::weight(Vertex vertex1, Vertex vertex2)
{
    return this->matrix[vertex1][vertex2];
}

Vertex MatrixGraph::first_vertex()
{   
    if (this->amount_vertex() == 0) {
        return Vertex();
    } else {
        return 0;
    }
}

Vertex MatrixGraph::next_vertex(Vertex vertex) {
    if (vertex == this->amount_vertex() - 1) {
        return Vertex();
    } else {
        return vertex + 1;
    }
}

Vertex MatrixGraph::first_adjacent(Vertex vertex) {
    for (int i = 0; i < this->amount_vertex(); i++) {
        if (this->matrix[vertex][i] != -1) {
            return i;
        }
    }
    return Vertex();
}


Vertex MatrixGraph::next_adjacent(Vertex vertex, Vertex adjacent)
{
    for (int i = adjacent + 1; i < this->amount_vertex(); i++) {
        if (this->matrix[vertex][i] != -1) {
            return i;
        }
    }
    return Vertex();
}


