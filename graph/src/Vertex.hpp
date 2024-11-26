#pragma once
#include <functional> // Para std::hash
#include <cstddef>    // Para size_t

#define NULL_VERTEX -1

class Vertex {

    private:
        int number;

    public:
        Vertex(int number) : number(number) {}
        Vertex() : number(-1) {}
        ~Vertex();

        int operator  ++();
        int operator --();
        bool operator  == (const Vertex& number);
        bool operator == (const int number);
        operator int() const;

        // Getter para el número (útil para hashing)
        int get_number() const { return number; }
};

namespace std {
    template <>
    struct hash<Vertex> {
        size_t operator()(const Vertex& vertex) const {
            return std::hash<int>()(vertex.get_number());
        }
    };
}