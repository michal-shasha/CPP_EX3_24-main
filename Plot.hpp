#pragma once
#include <string>
#include <vector>
#include "Resource.hpp" // Assuming Resource is an enum class defined elsewhere

class Vertex; // Forward declaration

class Plot {
private:
    Resource resource;
    int number;
    std::size_t index;
    std::vector<Vertex*> vertices;

public:
    Plot(Resource resource, int number, std::size_t index); 
    Resource getResource() const;
    int getNumber() const;
    std::size_t getIndex() const;
    const std::vector<Vertex*>& getVertices() const;
    void setVertex(Vertex* vertex);
};