#include "Player.hpp"
#include "Board.hpp"
#include <stdexcept>
#include <iostream>
#include <cstdlib> // For rand()

// Constructor for the Player class
Player::Player(std::string name, int id) : name(name), points(0), id(id){
    resources[Resource::WOOD] = 0;
    resources[Resource::BRICK] = 0;
    resources[Resource::WOOL] = 0;
    resources[Resource::WHEAT] = 0;
    resources[Resource::IRON] = 0;
    resources[Resource::DESERT] = 0;

}
// Getter for player's name
std::string Player::getName() const {
    return name;
}
// Function to place a settlement on the board
void Player::placeSettlement(const std::vector<int>& placesNum, Board& board, bool isFirstRun) {
    if (isFirstRun) {
        // Force a successful placement for the first run
        if (!placesNum.empty()) {
            int vertexIndex = placesNum[0];
            // Check if the player has enough resources to buy a settlement
            if(board.canPlaceInitialSettlement(*this, size_t(vertexIndex))){

                
                settlements.push_back(vertexIndex);
                std::cout << "Player " << this->getName() << " placed a settlement on vertex " << vertexIndex << std::endl;
                points += 1;
                // Print the resources that the player has after placing the settlement
                std::cout << "Player " << this->getName() << " now has resources: ";
                for (const auto& resource : resources) {
                    std::cout << resource.first << ": " << resource.second << ", ";
                }
                std::cout << std::endl;
                // Print the points that the player has after placing the settlement
                std::cout << "Player " << this->getName() << " now has " << points << " points" << std::endl;
            }
            // Check if the player won the game
            if (points >= 10) {
                // Mark the player as the winner
                this->setWinner(true);
                std::cout << "Player " << this->getName() << " won the game!" << std::endl;
            }
            
            return;  // Early return to avoid further checks
        } else {
            std::cout << "No available places for settlement on the first run" << std::endl;
            return;
        }
    }
    
    // Regular placement logic for subsequent runs
    for (int vertexIndex : placesNum) {
        if (!canbuySettlement()) {
            std::cout << "Player " << this->getName() << " cannot place a settlement because they are broke" << std::endl;
            return;
        }

        if (board.canPlaceSettlement(this->getId(), static_cast<std::size_t>(vertexIndex))) {
            settlements.push_back(vertexIndex);
            std::cout << "Player " << this->getName() << " placed a settlement on vertex " << vertexIndex << std::endl;
            for (auto& resource : resources) {
                // Decrease each resource quantity by 1
                resource.second -= 1;
            }
            points += 1;
            // Print the resources that the player has after placing the settlement
            std::cout << "Player " << this->getName() << " now has resources: ";
            for (const auto& resource : resources) {
                std::cout << resource.first << ": " << resource.second << ", ";
            }
            std::cout << std::endl;
            // Print the points that the player has after placing the settlement
            std::cout << "Player " << this->getName() << " now has " << points << " points" << std::endl;
            // Check if the player won the game
            if (points >= 10) {
                // Mark the player as the winner
                this->setWinner(true);
                std::cout << "Player " << this->getName() << " won the game!" << std::endl;
            }
        } else {
            std::cout << "Player " << this->getName() << " cannot place a settlement on vertex " << vertexIndex << std::endl;
        }
    }
}



  void Player::setWinner(bool isWinner) {
        winner = isWinner;
  }



int Player::rollDice() {
    int roll1 = rand() % 6 + 1;
    int roll2 = rand() % 6 + 1;
    int sum = roll1 + roll2;
    std::cout << name << " rolled a " << roll1 << " and a " << roll2 << ", summing up to " << sum << "." << std::endl;
    return sum;
}

void Player::printPoints() const {
    std::cout << name << " has " << points << " points." << std::endl;
}

void Player::trade(Player& otherPlayer, Resource fromResource, Resource toResource, int fromAmount, int toAmount) {
    if (resources[fromResource] < fromAmount) {
        throw std::runtime_error(name + " does not have enough " + resourceToString(fromResource) + " to trade.");
    }

    if (otherPlayer.resources[toResource] < toAmount) {
        throw std::runtime_error(otherPlayer.name + " does not have enough " + resourceToString(toResource) + " to trade.");
    }

    resources[fromResource] -= fromAmount;
    otherPlayer.resources[fromResource] += fromAmount;

    resources[toResource] += toAmount;
    otherPlayer.resources[toResource] -= toAmount;

    std::cout << name << " traded " << fromAmount << " " << resourceToString(fromResource) << " with " << otherPlayer.name
              << " for " << toAmount << " " << resourceToString(toResource) << "." << std::endl;
}

int Player::getPoints() const {
    return points;
}

void Player::addResource(Resource resource, int quantity) {
    switch (resource) {
        case Resource::WOOD:
        case Resource::BRICK:
        case Resource::WOOL:
        case Resource::WHEAT:
        case Resource::IRON:
            resources[resource] += quantity;
            break;
        case Resource::DESERT:
            std::cerr << "Invalid resource type: DESERT cannot be added" << std::endl;
            break;
        default:
            // Handle invalid resource
            std::cerr << "Invalid resource type" << std::endl;
            break;
    }
}

std::map<Resource, int> &Player::getResources()
{
    return resources;
}

void Player::addDevelopmentCard(const std::string& cardType) {
    developmentCards.push_back(cardType);
}

std::vector<std::string>& Player::getDevelopmentCards() {
    return developmentCards;
}

int Player::getId() const {
    return id;
}

bool Player::canbuySettlement() const {
    // Define the resource requirements for a settlement
    int woodRequired = 1;
    int brickRequired = 1;
    int woolRequired = 1;
    int wheatRequired = 1;

    // Check if the player has enough resources to buy a settlement
  if (resources.at(Resource::WOOD) < woodRequired ||
     resources.at(Resource::BRICK) < brickRequired ||
     resources.at(Resource::WOOL) < woolRequired ||
     resources.at(Resource::WHEAT) < wheatRequired) {
        // Player doesn't have enough resources to buy a settlement
        return false;
    }
    
    // Player has enough resources to buy a settlement
    return true;
}

void Player::placeRoad(int vertexIndex1, int vertexIndex2, Board& board, bool isFirstRun) {
    if (isFirstRun) {
        if(board.canPlaceInitialRoad(*this, size_t(vertexIndex1),size_t(vertexIndex2))){
            // Force a successful placement for the first run
            roads.push_back(vertexIndex1);
            std::cout << "Player " << this->getName() << " placed a road between vertices " << vertexIndex1 << " and " << vertexIndex2 << std::endl;
            // Update player's resources or other relevant data
            return;  // Early return to avoid further checks
        }
    }
    else{
    if (!canBuyRoad()) {
        std::cout << "Player " << this->getName() << " cannot buy a road because they are broke" << std::endl;
        return;
    }

    if (board.canPlaceRoad(this->getId(), static_cast<std::size_t>(vertexIndex1), static_cast<std::size_t>(vertexIndex2))) {
        roads.push_back(vertexIndex1);
        std::cout << "Player " << this->getName() << " placed a road between vertices " << vertexIndex1 << " and " << vertexIndex2 << std::endl;
        // Update player's resources or other relevant data
    } else {
        std::cout << "Player " << this->getName() << " cannot place a road between vertices " << vertexIndex1 << " and " << vertexIndex2 << std::endl;
    }
}
}




bool Player::canBuyRoad() const {
    // Check if the player has enough resources to buy a road
    return resources.at(Resource::BRICK) >= 1 && resources.at(Resource::WOOD) >= 1;
}

void Player::tradeResources(Board& board, int otherPlayerId, Resource fromResource, int fromAmount, Resource toResource, int toAmount) {
    Player& otherPlayer = board.getPlayerById(otherPlayerId);

    if (resources[fromResource] < fromAmount) {
        std::cout<< " does not have enough " + resourceToString(fromResource) + " to trade." << std::endl;
    }

    if (otherPlayer.resources[toResource] < toAmount) {
        std:: cout<< otherPlayer.getName() + " does not have enough " + resourceToString(toResource) + " to trade." << std::endl;
    }

    resources[fromResource] -= fromAmount;
    otherPlayer.resources[toResource] -= toAmount;

    resources[toResource] += toAmount;
    otherPlayer.resources[fromResource] += fromAmount;

    std::cout << name << " traded " << fromAmount << " " << resourceToString(fromResource) << " with " << otherPlayer.getName()
              << " for " << toAmount << " " << resourceToString(toResource) << "." << std::endl;
}


void Player::chooseDevelopmentCard(Board& board) {
    if (!canBuyDevelopmentCard()) {
        std::cout << "Player " << this->getName() << " cannot buy a development card " << std::endl;
        return;
    }

    // Draw a development card from the board
    board.drawDevelopmentCard(this->getId());
    // Update player's resources or other relevant data
}

bool Player::canBuyDevelopmentCard() const {
    // Check if the player has enough resources to buy a development card
    return resources.at(Resource::WOOL) >= 1 && resources.at(Resource::WHEAT) >= 1 && resources.at(Resource::IRON) >= 1;
}

void Player::upgradeToCity(int vertexIndex, Board& board) {
    if (!canBuyCity()) {
        std::cout << "Player " << this->getName() << " cannot upgrade to a city because they are broke" << std::endl;
        return;
    }

    if (board.canPlaceCity(this->getId(), static_cast<std::size_t>(vertexIndex))) {
        settlements.push_back(vertexIndex);
        std::cout << "Player " << this->getName() << " upgraded a settlement to a city on vertex " << vertexIndex << std::endl;
        // Update player's resources or other relevant data
        resources[Resource::WOOD] -= 2;
        resources[Resource::IRON] -= 3;
        points += 1;
        std::cout << "Player " << this->getName() << " now has " << points << " points" << std::endl;
    } else {
        std::cout << "Player " << this->getName() << " cannot upgrade a settlement to a city on vertex " << vertexIndex << std::endl;
    }
}


bool Player::isWinner() const {
    return winner;
}

bool Player::canBuyCity() const {
    // Check if the player has enough resources to buy a city
    return resources.at(Resource::WHEAT) >= 2 && resources.at(Resource::IRON) >= 3;

}



