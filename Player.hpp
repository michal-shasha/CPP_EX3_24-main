#pragma once
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "Resource.hpp"
#include "Board.hpp" 


// Forward declaration of Board class
class Board;

class Player {
public:
    Player(std::string name, int id);

    std::string getName() const;

    void placeSettlement(const std::vector<int>& placesNum, Board& board, bool istarting);
    int rollDice();
    void printPoints() const;
    void chooseDevelopmentCard(Board& board);
    void upgradeToCity(int vertexIndex, Board& board);

    void trade(Player& otherPlayer, Resource fromResource, Resource toResource, int fromAmount, int toAmount);

    int getPoints() const;
    int getId() const;

    void addDevelopmentCard(const std::string& cardType);
    std::vector<std::string>& getDevelopmentCards();
    bool canbuySettlement() const;
    void setWinner(bool isWinner);
    void placeRoad(int vertexIndex1, int vertexIndex2, Board& board, bool isStarting);
    bool canBuyRoad() const;
    bool canBuyCity() const;
    bool canBuyDevelopmentCard() const;
    void tradeResources(Board& board, int otherPlayerId, Resource fromResource, int fromAmount, Resource toResource, int toAmount);
    bool isWinner() const;
    void addResource(Resource resource, int quantity); 
    std::map<Resource, int>& getResources();
private:
    std::string name;
    int points;
    int id;
    bool winner = false;
    std::map<Resource, int> resources; 
    std::vector<std::string> developmentCards;
    std::vector<int> settlements;
    std::vector<int> roads;
};
