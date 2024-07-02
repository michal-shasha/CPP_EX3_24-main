**Assignment 3-Katan**

**Classes I used:**
**Board-** The Board class represents the game board for a game of Catan.
           Constructor (board::board(player &player1, player &player2, player &player3))- Initializes the game board when it appears with three players. It defines players, plots (play locations with resources and dice numbers), vertices (intersecting points on the board), edges (roads connecting vertices), and development cards for the game.

           In addition, in this class there are functions that together define the behavior and actions of the board class. They handle various aspects such as initializing the board, managing player actions (placing settlements, roads, cities), distributing resources, issuing development cards and determining the state of the game (printing board state, declaring a winner). Each function serves a specific purpose in maintaining game rules and facilitating game interactions.

**Player-**  The Player class manages player data and in-game interactions. 
             It handles player attributes such as name, ID, points, resources, development cards, settlements, roads and methods for performing actions such as placing settlements, rolling dice, trading and upgrading settlements to cities. Each function contributes to the player's ability to interact with the game board and with other players, while adhering to the rules of the game.

             Constructor (Player::Player(std::string name, int id)): Initializes a player with a name, id, and initializes their resource quantities to zero (WOOD, BRICK, WOOL, WHEAT, IRON, DESERT).

**Vertex-** The Vertex class represents a vertex in the game. 
            It stores information such as ID, owner, neighbors, edges, and city name. The department provides methods for manipulating and retrieving this information, and makes it possible to perform operations such as adding neighbors and edges, defining and receiving information about owners and the city, checking neighbors and managing metrics.

            Constructor (Vertex::Vertex(int id)): Initializes a vertex with a given id. The owner is initialized to -1 (indicating no owner initially), and index is initialized to 0

**Plot-** The Plot class contains attributes such as the resource type (resource),
          numeric value (number) and index (index). In addition, it maintains relationships to vertices (vertex objects) through a vector (vertices). This department enables management and access to specific plot-related information in the context of a built envireonment, and facilitates operations such as resource management, spatial relationships and connectivity within the wider system.

          Constructor (Plot::Plot(resource resource, int number, std::size_t index)): Initializes a Plot object with the specified resource, number, and index.

**Edge-** The Edge class represents a connection between two vertices in the game.

**Resource-** Converts a string representation of a resource to the corresponding Resource enum value.

**DevelopmentCard-** The DevelopmentCard class is simple, containing only the components necessary to represent and access the development card type.




**Libraries used-** <iostream>: For input and output operations.
                    <string>: For handling strings.
                    <vector>: For dynamic array handling.
                    <map>: For associative arrays (mapping resources to quantities).
                    <stdexcept>: For handling exceptions.
                    <cstdlib>: For random number generation.
                    <limits>: For handling maximum and minimum values





**Game Rules - Settlers of Catan-**
Purpose-
The goal of the game is to be the first player to reach 10 victory points. Players gain victory points by building settlements, cities and purchasing special development cards.

Game components-
Plots of land: The council consists of 19 plots of land, each of which produces a specific resource: wood ,bricks ,wool ,wheat ,iron ,desert 

Settlements, cities and roads:
Settlement: Building a settlement gives one victory point. The cost is 1 wood, 1 brick, 1 wool and 1 wheat. A settlement must be at least two road sections away from another settlement.

City: Upgrading a settlement to a city costs 3 iron and 2 wheat. A city grants 2 victory points and produces double the resources of the adjacent plots.

Road: Building a road section costs 1 wood and 1 brick. The road must be connected to a player's settlement, city or other road section.

Development Cards: The cost of a development card is 1 iron, 1 wool, and 1 wheat. There are three types of cards:

Progress Cards -(Monopoly, Road Building, Year of Plenty)
Knight Cards -(3 such cards grant the Largest Army card, which gives 2 victory points)
Victory Point Cards -(each grants 1 victory point)



**Game Flow-**
Starting the Game:
Each player starts with 2 settlements and 2 road segments.
Players receive starting resources based on the location of their settlements (one resource of each type).
Turn Order: Determined randomly.

Player Turn:

Each player rolls 2 dice.
Based on the dice roll, players receive resources from land plots with matching numbers (e.g., if a 3 is rolled, players receive resources from plots numbered 3).
The player can then:
Trade resources with other players.
Build roads, settlements, or cities.
Buy development cards.
Use a development card (if used, the turn immediately ends).
Ending the Game
The game ends when a player reaches 10 victory points on their turn. The first player to do so wins the game.








