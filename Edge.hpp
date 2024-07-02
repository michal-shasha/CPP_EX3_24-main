#pragma once
#include <cstddef>

class Vertex; // Forward declaration

class Edge {
private:
    std::size_t index;
    Vertex* vertex1;
    Vertex* vertex2;
    int owner;

public:
    Edge(std::size_t index);
    std::size_t getIndex() const;
    Vertex* getVertex1() const;
    Vertex* getVertex2() const;
    int getOwner() const;
    void setOwner(int owner);
    void setVertices(Vertex* vertex1, Vertex* vertex2);
};


