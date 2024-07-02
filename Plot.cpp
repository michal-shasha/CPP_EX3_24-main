#include "Plot.hpp"
#include "Vertex.hpp"

Plot::Plot(Resource resource, int number, std::size_t index)
    : resource(resource), number(number), index(index) {}

Resource Plot::getResource() const {
    return resource;
}

int Plot::getNumber() const {
    return number;
}

std::size_t Plot::getIndex() const {
    return index;
}

const std::vector<Vertex*>& Plot::getVertices() const {
    return vertices;
}

void Plot::setVertex(Vertex* vertex) {
    vertices.push_back(vertex);
}