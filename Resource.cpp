#include "Resource.hpp"
#include <stdexcept>

std::string resourceToString(Resource res) {
    switch (res) {
        case Resource::WOOD: return "WOOD";
        case Resource::BRICK: return "BRICK";
        case Resource::WOOL: return "WOOL";
        case Resource::WHEAT: return "WHEAT";
        case Resource::IRON: return "IRON";
        case Resource::DESERT: return "DESERT";
        default: throw std::invalid_argument("Invalid resource");
    }
}

std::ostream& operator<<(std::ostream& os, const Resource& res) {
    os << resourceToString(res);
    return os;
}

Resource stringToResource(const std::string& resourceString) {
    if (resourceString == "WOOD") {
        return Resource::WOOD;
    } else if (resourceString == "BRICK") {
        return Resource::BRICK;
    } else if (resourceString == "WOOL") {
        return Resource::WOOL;
    } else if (resourceString == "WHEAT") {
        return Resource::WHEAT;
    } else if (resourceString == "IRON") {
        return Resource::IRON;
    } else if (resourceString == "DESERT") {
        return Resource::DESERT;
    } else {
        throw std::invalid_argument("Invalid resource string");
    }
}
