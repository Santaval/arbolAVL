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


void MatrixGraph::modify_element(Vertex vertex, char newElement)
{
}

char MatrixGraph::element(Vertex vertex)
{
    return 0;
}

void MatrixGraph::add_edge(Vertex vertex1, Vertex vertex2, double weight)
{
}

void MatrixGraph::delete_edge(Vertex vertex1, Vertex vertex2)
{
}

void MatrixGraph::modify_weight(Vertex vertex1, Vertex vertex2, double newWeight)
{
}

double MatrixGraph::weight(Vertex vertex1, Vertex vertex2)
{
    return 0;
}

Vertex MatrixGraph::first_vertex()
{
    return Vertex();
}

Vertex MatrixGraph::next_vertex(Vertex vertex)
{
    return Vertex();
}

Vertex MatrixGraph::first_adjacent(Vertex vertex)
{
    return Vertex();
}

Vertex MatrixGraph::next_adjacent(Vertex vertex, Vertex adjacent)
{
    return Vertex();
}


void MatrixGraph::print_matrix() {
    for (int i = 0; i < this->amount_vertex(); i++) {
        for (int j = 0; j < this->amount_vertex(); j++) {
            std::cout << this->matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void MatrixGraph::print_elements() {
    for (int i = 0; i < this->amount_vertex(); i++) {
        std::cout << this->elements[i] << " ";
    }
    std::cout << std::endl;
}

