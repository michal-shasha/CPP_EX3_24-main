#pragma once

#include <string>
#include <ostream>

enum class Resource {
    WOOD,
    BRICK,
    WOOL,
    WHEAT,
    IRON,
    DESERT
};

std::string resourceToString(Resource res);

std::ostream& operator<<(std::ostream& os, const Resource& res);

Resource stringToResource(const std::string& resourceString);
