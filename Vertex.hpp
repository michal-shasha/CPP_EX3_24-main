#pragma once
#include <vector>
#include <string>
#include "Edge.hpp"

class Vertex {
public:
    Vertex(int id);

    int getId() const;

    void addNeighbor(Vertex* neighbor);
    const std::vector<Vertex*>& getNeighbors() const;

    void addEdge(Edge* edge);
    std::vector<Edge*> getEdges() const;

    void setOwner(int owner);
    int getOwner() const;

    void setCity(const std::string &city);
    std::string getCity() const;

    bool isNeighbor(const Vertex& other) const;

private:
    int id;
    int owner;
    std::string city;
    std::vector<Vertex*> neighbors;
    std::vector<Edge*> edges;
};