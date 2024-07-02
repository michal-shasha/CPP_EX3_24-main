// #include <iostream>
// #include <stdexcept>
// #include <vector>
// #include "Catan.hpp"
// #include "Player.hpp"
// #include "Board.hpp"
// using namespace std;

//int main()
// {
//     Player p1("Amit");
//     Player p2("Yossi");
//     Player p3("Dana");
//     Catan catan(p1, p2, p3);

//     catan.ChooseStartingPlayer();   // should print the name of the starting player, assume it is Amit.
//     Board board = *catan.getBoard(); // get the board of the game.
 
//     std::vector<std::string> places1 = {"Forest", "Hills"};
//     std::vector<int> placesNum1 = {5, 6};
//     p1.placeSettlement(places1, placesNum1, board);
//     p1.placeRoad(places1, placesNum1, board);

//     std::vector<std::string> places2 = {"Agricultural Land", "Desert"};
//     std::vector<int> placesNum2 = {3, 4};
//     p1.placeSettlement(places2, placesNum2, board);
//     p1.placeRoad(places2, placesNum2, board); // p1 chooses Forest, hills, Agricultural Land, Desert with numbers 5, 6, 3, 4.

//     std::vector<std::string> places3 = {"Mountains", "Pasture Land"};
//     std::vector<int> placesNum3 = {4, 9};
//     p2.placeSettlement(places3, placesNum3, board);
//     p2.placeRoad(places3, placesNum3, board);

//     try {
//         p3.placeSettlement(places3, placesNum3, board); // p3 tries to place a settlement in the same location as p2.
//     } catch (const std::exception &e) {
//         std::cout << e.what() << std::endl;
//     }

//     std::vector<std::string> places4 = {"Forest", "Pasture Land"};
//     std::vector<int> placesNum4 = {5, 9};
//     p2.placeSettlement(places4, placesNum4, board);
//     p2.placeRoad(places4, placesNum4, board); // p2 chooses Mountains, Pasture Land, and Forest with numbers 4, 9, 5.

//     std::vector<std::string> places5 = {"Mountains", "Pasture Land"};
//     std::vector<int> placesNum5 = {3, 8};
//     p3.placeSettlement(places5, placesNum5, board);
//     p3.placeRoad(places5, placesNum5, board);

//     std::vector<std::string> places6 = {"Agricultural Land", "Pasture Land"};
//     std::vector<int> placesNum6 = {3, 9};
//     p3.placeSettlement(places6, placesNum6, board);
//     p3.placeRoad(places6, placesNum6, board); // p3 chooses Mountains, Pasture Land, Agricultural Land, Pasture Land with numbers 3, 8, 3, 9.

//     p1.rollDice(); // Lets say it's print 4. Then, p2 gets ore from the mountations.
//     p1.placeRoad(places1, placesNum1, board); // p1 continues to build a road.
//     p1.endTurn(); // p1 ends his turn.

//     p2.rollDice(); // Lets say it's print 9. Then, p3 gets wool from the Pasture Land, p2 gets wool from the Pasture Land.
//     p2.endTurn(); // p2 ends his turn.

//     p3.rollDice(); // Lets say it's print 3. Then, p3 gets wheat from the Agricultural Land and Ore from the Mountains, p1 gets wheat from the Agricultural Land.
//     p3.endTurn(); // p3 ends his turn.

//     try {
//         p2.rollDice(); // p2 tries to roll the dice again, but it's not his turn.
//     } catch (const std::exception &e) {
//         std::cout << e.what() << std::endl;
//     }

//     p1.rollDice(); // Lets say it's print 6. Then, p1 gets bricks from the hills.
//     p1.trade(p2, "wood", "brick", 1, 1); // p1 trades 1 wood for 1 brick with p2.
//     p1.endTurn(); // p1 ends his turn.

//     p2.rollDice(); // Lets say it's print 9. Then, p3 gets wool from the Pasture Land, p2 gets wool from the Pasture Land.
//     p2.buyDevelopmentCard(); // p2 buys a development card. Lets say it is a bonus points card.
//     p2.endTurn(); // p2 ends his turn.

//     p1.printPoints(); // p1 has 2 points because it has two settelments.
//     p2.printPoints(); // p2 has 3 points because it has two settelments and a bonus points card.
//     p3.printPoints(); // p3 has 2 points because it has two settelments.

//     catan.printWinner(); // Should print None because no player reached 10 points.
// };





#include <iostream>
#include <exception>
#include <ctime>
#include "Player.hpp"
#include "Board.hpp"

using namespace std;

int main() {
    srand(time(0)); // Use current time as seed for random generator

    // Create players
    Player player1("Player 1", 1);
    Player player2("Player 2", 2);
    Player player3("Player 3", 3);

    // Create board
    Board board(player1, player2, player3);
    bool firstRound = true;
    // Set the initial settlements and roads
    player1.placeSettlement({19}, board, firstRound);
    player1.placeRoad(19, 18, board, firstRound);
    player2.placeSettlement({44}, board, firstRound);
    player2.placeRoad(44, 34, board, firstRound);
    player3.placeSettlement({42}, board, firstRound);
    
    player3.placeRoad(42, 43, board, firstRound);
    player3.placeSettlement({13}, board, firstRound);
    player3.placeRoad(13, 12, board,firstRound);
    player2.placeSettlement({40}, board, firstRound);
    player2.placeRoad(40, 41, board, firstRound);
    player1.placeSettlement({35}, board, firstRound);
    player1.placeRoad(35, 24, board,firstRound);

    std::cout << "\nInitial settlements and roads placed.\n" << endl;

    // Simulate the first 2-3 rounds

    // Round 1
    firstRound=false;
    std::cout << "Round 1:\n" << endl;

    player1.rollDice();
    player1.placeRoad(25, 24, board,firstRound);
    player1.tradeResources(board, 2, Resource::BRICK, 1, Resource::IRON, 1);
    player1.placeSettlement({25}, board, false);

    player2.rollDice();
    player2.tradeResources(board, 3, Resource::BRICK, 1, Resource::IRON, 1);
    player2.placeRoad(33, 34, board, firstRound);
    player2.chooseDevelopmentCard(board);
    player2.placeSettlement({33}, board, firstRound); // Should not be able to place a settlement here

    player3.rollDice();
    player3.chooseDevelopmentCard(board);
    player3.upgradeToCity(13, board); // Should not be able to upgrade to a city here

    // Round 2
    std::cout << "\nRound 2:\n" << endl;

    player1.rollDice();
    player1.chooseDevelopmentCard(board);
    player1.tradeResources(board, 2, Resource::WOOL, 1, Resource::BRICK, 1);

    player2.rollDice();
    player2.placeRoad(32, 33, board, false);
    // Assuming useKnight method exists
    // player2.useKnight(board);

    player3.rollDice();
    player3.tradeResources(board, 1, Resource::WHEAT, 1, Resource::IRON, 1);
    player3.placeSettlement({14}, board, false);

    // Round 3
    std::cout << "\nRound 3:\n" << endl;

    player1.rollDice();
    player1.placeRoad(26, 25, board, false);
    player1.upgradeToCity(35, board);

    player2.rollDice();
    player2.chooseDevelopmentCard(board);
    player2.placeSettlement({34}, board, false);

    player3.rollDice();
    player3.tradeResources(board, 2, Resource::IRON, 1, Resource::BRICK, 1);
    player3.placeRoad(14, 15, board, false);

    // Print winner
    board.printWinner();
    
    return 0;
}








