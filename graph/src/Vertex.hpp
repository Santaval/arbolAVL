#pragma once
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
};