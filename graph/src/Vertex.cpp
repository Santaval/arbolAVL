#include "Vertex.hpp"



int Vertex::operator ++() {
    return this->number++;
}

int Vertex::operator --() {
    return this->number--;
}

bool Vertex::operator ==(const Vertex& vertex) {
    return this->number == vertex.number;
}

Vertex::operator int() const {
    return this->number;
}


Vertex::~Vertex() {
    this->number = 0;
}