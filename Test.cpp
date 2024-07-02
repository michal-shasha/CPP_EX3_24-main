#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Board.hpp"
#include "Player.hpp"
#include "Edge.hpp"
#include "DevelopmentCard.hpp"

using namespace std;

TEST_CASE("testBoardInitialization") {
    // Create mock players for testing
    Player player1("Alice", 1);
    Player player2("Bob", 2);
    Player player3("Eve", 3);

    // Initialize the board
    Board board(player1, player2, player3);

    // Example assertions to check initialization
    const auto& plots = board.getPlots();
    CHECK(plots.size() == 19); // Check number of plots
    CHECK(board.getVertices().size() == 54); // Check number of vertices
}

TEST_CASE("testPlaceSettlement") {
    Player player1("Alice", 1);
    Player player2("Bob", 2);
    Player player3("Eve", 3);

    // Initialize the board
    Board board(player1, player2, player3);

    // Place a settlement
    player1.placeSettlement({19}, board, true);

    // Check if the settlement was placed
    const auto& vertices = board.getVertices();
    CHECK(vertices[19].getOwner() == 1); // Check if the owner is correct
    CHECK(vertices[19].getCity() == "Settlement"); // Check if the city is correct
}

TEST_CASE("testPlaceRoad") {
    Player player1("Alice", 1);
    Player player2("Bob", 2);
    Player player3("Eve", 3);

    // Initialize the board
    Board board(player1, player2, player3);

    // Place a road
    player1.placeRoad(0, 1, board, true);

    // Check if the road was placed
    size_t edge_id = size_t(board.getEdge(0, 1));
    Edge edge = board.getEdges()[edge_id];
    CHECK(edge.getOwner() == 1); // Check if the road actually exists
}

TEST_CASE("testCanPlaceInitialSettlement") {
    Player player1("Alice", 1);
    Player player2("Bob", 2);
    Player player3("Eve", 3);

    // Initialize the board
    Board board(player1, player2, player3);

    // Check if a settlement can be placed
    CHECK(board.canPlaceInitialSettlement(player1, 19) == true);
    CHECK(board.canPlaceInitialSettlement(player1, 0) == false);

    // Place a settlement
    player1.placeSettlement({19}, board, true);

    // Check if a settlement can be placed
    CHECK(board.canPlaceInitialSettlement(player1, 0) == true);
    CHECK(board.canPlaceInitialSettlement(player1, 19) == false);   

}

TEST_CASE("testCanPlaceInitialRoad") {
    Player player1("Alice", 1);
    Player player2("Bob", 2);
    Player player3("Eve", 3);

    // Initialize the board
    Board board(player1, player2, player3);

    // Check if a road can be placed
    CHECK(board.canPlaceInitialRoad(player1, 0, 1) == true);
    CHECK(board.canPlaceInitialRoad(player1, 0, 2) == false);

    // Place a road
    player1.placeRoad(0, 1, board, true);

    // Check if a road can be placed
    CHECK(board.canPlaceInitialRoad(player1, 0, 2) == true);
    CHECK(board.canPlaceInitialRoad(player1, 0, 1) == false);

}    

TEST_CASE("testCanPlaceRoad") {
    Player player1("Alice", 1);
    Player player2("Bob", 2);
    Player player3("Eve", 3);

    // Initialize the board
    Board board(player1, player2, player3);

    // Check if a road can be placed
    CHECK(board.canPlaceRoad(1, 0, 1) == true);
    CHECK(board.canPlaceRoad(1, 0, 2) == false);

    // Place a road
    player1.placeRoad(0, 1, board, true);

    // Check if a road can be placed
    CHECK(board.canPlaceRoad(1, 0, 2) == true);
    CHECK(board.canPlaceRoad(1, 0, 1) == false);
}

TEST_CASE("testCanPlaceCity") {
    Player player1("Alice", 1);
    Player player2("Bob", 2);
    Player player3("Eve", 3);

    // Initialize the board
    Board board(player1, player2, player3);

    // Check if a city can be placed
    CHECK(board.canPlaceCity(1, 0) == false);
    CHECK(board.canPlaceCity(1, 19) == false);

    // Place a settlement
    player1.placeSettlement({19}, board, true);

    // Check if a city can be placed
    CHECK(board.canPlaceCity(1, 19) == true);
    CHECK(board.canPlaceCity(1, 0) == false);
}

TEST_CASE("testCanPlaceSettlement") {
    Player player1("Alice", 1);
    Player player2("Bob", 2);
    Player player3("Eve", 3);

    // Initialize the board
    Board board(player1, player2, player3);

    // Check if a settlement can be placed
    CHECK(board.canPlaceSettlement(1, 0) == true);
    CHECK(board.canPlaceSettlement(1, 19) == false);

    // Place a settlement
    player1.placeSettlement({19}, board, true);

    // Check if a settlement can be placed
    CHECK(board.canPlaceSettlement(1, 0) == true);
    CHECK(board.canPlaceSettlement(1, 19) == false);
} 

TEST_CASE("developmentCardTest") {
    Player player1("Alice", 1);
    Player player2("Bob", 2);
    Player player3("Eve", 3);

    // Initialize the board
    Board board(player1, player2, player3);

    // Draw a development card (assuming drawDevelopmentCard(1) works correctly)
    board.drawDevelopmentCard(1);

    // Check if the player has a development card
    CHECK(player1.getDevelopmentCards().size() == 1);

    // Check if the player has the correct development card
    CHECK(player1.getDevelopmentCards()[0] == "KNIGHT");
}
   

TEST_CASE("tradeTest") {
    Player player1("Alice", 1);
    Player player2("Bob", 2);
    Player player3("Eve", 3);

    // Initialize the board
    Board board(player1, player2, player3);

    // Trade resources
    player1.addResource(Resource::WOOD, 1);
    player1.addResource(Resource::BRICK, 1);
    player1.addResource(Resource::WOOL, 1);
    player1.addResource(Resource::WHEAT, 1);
    player1.addResource(Resource::IRON, 1);

    player2.addResource(Resource::WOOD, 1);
    player2.addResource(Resource::BRICK, 1);
    player2.addResource(Resource::WOOL, 1);
    player2.addResource(Resource::WHEAT, 1);
    player2.addResource(Resource::IRON, 1);

    player1.trade(player2, Resource::WOOD, Resource::BRICK, 1, 1);

    // Check if the trade was successful
    CHECK(player1.getResources()[Resource::WOOD] == 0);
    CHECK(player1.getResources()[Resource::BRICK] == 2);
    CHECK(player2.getResources()[Resource::WOOD] == 2);
    CHECK(player2.getResources()[Resource::BRICK] == 0);

}    

TEST_CASE("addResourceTest") {
    Player player1("Alice", 1);
    Player player2("Bob", 2);
    Player player3("Eve", 3);

    // Initialize the board
    Board board(player1, player2, player3);

    // Add resources
    player1.addResource(Resource::WOOD, 1);
    player1.addResource(Resource::BRICK, 1);
    player1.addResource(Resource::BRICK, 1);
    player1.addResource(Resource::WOOL, 1);
    player1.addResource(Resource::WHEAT, 1);
    player1.addResource(Resource::IRON, 1);

    // Check if the resources were added
    CHECK(player1.getResources()[Resource::WOOD] == 1);
    CHECK(player1.getResources()[Resource::BRICK] == 2);
    CHECK(player1.getResources()[Resource::WOOL] == 1);
    CHECK(player1.getResources()[Resource::WHEAT] == 1);
    CHECK(player1.getResources()[Resource::IRON] == 1);

}

TEST_CASE("canBuySettlementTest") {
    Player player1("Alice", 1);
    Player player2("Bob", 2);
    Player player3("Eve", 3);

    // Initialize the board
    Board board(player1, player2, player3);

    // Check if a settlement can be bought
    CHECK(player1.canbuySettlement() == false);

    // Add resources
    player1.addResource(Resource::WOOD, 1);
    player1.addResource(Resource::BRICK, 1);
    player1.addResource(Resource::WOOL, 1);
    player1.addResource(Resource::WHEAT, 1);

    // Check if a settlement can be bought
    CHECK(player1.canbuySettlement() == true);

}  

TEST_CASE("canBuyRoadTest") {
    Player player1("Alice", 1);
    Player player2("Bob", 2);
    Player player3("Eve", 3);

    // Initialize the board
    Board board(player1, player2, player3);

    // Check if a road can be bought
    CHECK(player1.canBuyRoad() == false);

    // Add resources
    player1.addResource(Resource::WOOD, 1);
    player1.addResource(Resource::BRICK, 1);

    // Check if a road can be bought
    CHECK(player1.canBuyRoad() == true);

}

TEST_CASE("canBuyCityTest") {
    Player player1("Alice", 1);
    Player player2("Bob", 2);
    Player player3("Eve", 3);

    // Initialize the board
    Board board(player1, player2, player3);

    // Check if a city can be bought
    CHECK(player1.canBuyCity() == false);

    // Add resources
    player1.addResource(Resource::WOOD, 3);
    player1.addResource(Resource::BRICK, 2);
    player1.addResource(Resource::IRON, 3);
    player1.addResource(Resource::WHEAT, 2);
    player1.addResource(Resource::WOOL, 2);

    // Check if a city can be bought
    CHECK(player1.canBuyCity() == true);

}

TEST_CASE("canBuyDevelopmentCardTest") {
    Player player1("Alice", 1);
    Player player2("Bob", 2);
    Player player3("Eve", 3);

    // Initialize the board
    Board board(player1, player2, player3);

    // Check if a development card can be bought
    CHECK(player1.canBuyDevelopmentCard() == false);

    // Add resources
    player1.addResource(Resource::WOOD, 1);
    player1.addResource(Resource::BRICK, 1);
    player1.addResource(Resource::WOOL, 1);

    // Check if a development card can be bought
    CHECK(player1.canBuyDevelopmentCard() == true);

}    

TEST_CASE("rollDiceTest") {
    Player player1("Alice", 1);
    Player player2("Bob", 2);
    Player player3("Eve", 3);

    // Roll the dice
    int diceRoll = player1.rollDice();

    // Check if the dice roll is within the correct range
    CHECK(diceRoll >= 2);
    CHECK(diceRoll <= 12);

}

TEST_CASE("getPointsTest") {
    Player player1("Alice", 1);
    Player player2("Bob", 2);
    Player player3("Eve", 3);

    // Check if the points are correct
    CHECK(player1.getPoints() == 0);

    // Add points
    player1.addResource(Resource::WOOD, 1);
    player1.addResource(Resource::BRICK, 1);
    player1.addResource(Resource::WOOL, 1);
    player1.addResource(Resource::WHEAT, 1);
    player1.addResource(Resource::IRON, 1);

    // Check if the points are correct
    CHECK(player1.getPoints() == 1);
}

TEST_CASE("upgradeToCityTest") {
    Player player1("Alice", 1);
    Player player2("Bob", 2);
    Player player3("Eve", 3);

    // Initialize the board
    Board board(player1, player2, player3);

    // Place a settlement
    player1.placeSettlement({19}, board, true);
    
    // Upgrade to a city
    player1.upgradeToCity(19, board);

    // Check if the city was upgraded
    const auto& vertices = board.getVertices();
    CHECK(vertices[19].getCity() == "City");
}

TEST_CASE("setWinnerTest") {
    Player player1("Alice", 1);
    Player player2("Bob", 2);
    Player player3("Eve", 3);

    // Check if the player is not a winner
    CHECK(player1.isWinner() == false);

    // Set the player as a winner
    player1.setWinner(true);

    // Check if the player is a winner
    CHECK(player1.isWinner() == true);
}    

TEST_CASE("isNeighborTest") {
    Player player1("Alice", 1);
    Player player2("Bob", 2);
    Player player3("Eve", 3);

    Vertex vertex1(1);
    Vertex vertex2(2);
    Vertex vertex3(3);

    // Add neighbors
    vertex1.addNeighbor(&vertex2);
    vertex1.addNeighbor(&vertex3);

    // Check if the vertices are neighbors
    CHECK(vertex1.isNeighbor(vertex2) == true);
    CHECK(vertex1.isNeighbor(vertex3) == true);
    CHECK(vertex2.isNeighbor(vertex3) == false);

}  

TEST_CASE("resourceStringTest") {
    Player player1("Alice", 1);
    Player player2("Bob", 2);
    Player player3("Eve", 3);

    Board board(player1, player2, player3);

    // Check if the resource string is converted correctly
    CHECK(board.stringToResource("WOOD") == Resource::WOOD);
    CHECK(board.stringToResource("BRICK") == Resource::BRICK);

    // Check if an invalid resource string throws an exception
    CHECK_THROWS_AS(board.stringToResource("INVALID"), std::invalid_argument);

}

TEST_CASE("printWinnerTest") {
    Player player1("Alice", 1);
    Player player2("Bob", 2);
    Player player3("Eve", 3);

    // Set the winner
    player1.setWinner(true);
    
    // Check if the winner is printed correctly
    CHECK(player1.isWinner() == true);

}    


