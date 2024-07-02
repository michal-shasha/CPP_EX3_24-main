#include "Edge.hpp"
#include "Vertex.hpp"

Edge::Edge(std::size_t index) : index(index), vertex1(nullptr), vertex2(nullptr), owner(-1) {}

std::size_t Edge::getIndex() const {
    return index;
}

Vertex* Edge::getVertex1() const {
    return vertex1;
}

Vertex* Edge::getVertex2() const {
    return vertex2;
}

int Edge::getOwner() const {
    return owner;
}

void Edge::setOwner(int owner) {
    this->owner = owner;
}

void Edge::setVertices(Vertex* vertex1, Vertex* vertex2) {
    this->vertex1 = vertex1;
    this->vertex2 = vertex2;
}