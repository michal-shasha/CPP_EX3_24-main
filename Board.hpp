#pragma once
#include <vector>
#include <memory>
#include "Player.hpp"
#include "Plot.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include "DevelopmentCard.hpp"

class Player;

class Board {
public:
    Board(Player &player1, Player &player2, Player &player3);
    std::vector<Vertex>& getVertices();
    std::vector<Edge>& getEdges();
    void printBoard();
    const std::vector<Plot>& getPlots() const;
    int getEdge(std::size_t vertexIndex1, std::size_t vertexIndex2);
    void giveResources(std::vector<Player*>& players, int diceRoll);
    void drawDevelopmentCard(int playerId);
    bool canPlaceInitialSettlement(Player &player, std::size_t vertexIndex);
    bool canPlaceInitialRoad(Player &player, std::size_t vertexIndex, std::size_t vertexIndex2);
    bool canPlaceRoad(int playerId, std::size_t vertexIndex1, std::size_t vertexIndex2);
    bool canPlaceCity(int playerId, std::size_t vertexIndex);
    bool canPlaceSettlement(int playerId, std::size_t vertexIndex);
    void placeSettlement(const std::string& place, int placeNum, Player* player);
    Player& getPlayerById(int playerId) ; 
    void printWinner() const;

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

private:
    std::vector<Plot> plots;
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
    std::vector<DevelopmentCard> developmentCards;
    std::vector<Player*> players;
   
};
    

