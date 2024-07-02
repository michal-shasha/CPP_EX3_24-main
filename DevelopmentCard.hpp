#pragma once
#include <string>

class DevelopmentCard {
public:
    explicit DevelopmentCard(const std::string& type);

    const std::string& getType() const;

private:
    std::string type;
};