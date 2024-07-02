#include "Vertex.hpp"
#include <limits>

// Constructor
Vertex::Vertex(int id) : id(id), owner(-1) {}


// Get the vertex ID
int Vertex::getId() const {
    return id;
}

// Add a neighboring vertex
void Vertex::addNeighbor(Vertex* neighbor) {
    neighbors.push_back(neighbor);
}

// Get neighbors
const std::vector<Vertex*>& Vertex::getNeighbors() const {
    return neighbors;
}

// Add an edge
void Vertex::addEdge(Edge* edge) {
    edges.push_back(edge);
}

// Get edges
std::vector<Edge*> Vertex::getEdges() const {
    return edges;
}

// Set the owner of the vertex
void Vertex::setOwner(int owner) {
    this->owner = owner;
}

// Get the owner of the vertex
int Vertex::getOwner() const {
    return owner;
}

// Set the city name
void Vertex::setCity(const std::string &city) {
    this->city = city;
}

// Get the city name
std::string Vertex::getCity() const {
    return city;
}

// Check if the vertex is a neighbor
bool Vertex::isNeighbor(const Vertex& other) const {
    for (auto neighbor : neighbors) {
        if (neighbor->getId() == other.getId()) {
            return true;
        }
    }
    return false;
}

