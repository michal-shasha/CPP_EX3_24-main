#include "Board.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include "Plot.hpp"
#include <iostream>
#include <vector>
#include <tuple>
#include "DevelopmentCard.hpp"
#include <algorithm>
#include "Resource.hpp"

Board::Board(Player &player1, Player &player2, Player &player3)
{
    std::cout << "Initializing board..." << std::endl;
    // Initialize players
    players.push_back(&player1);
    players.push_back(&player2);
    players.push_back(&player3);
    
    // Plot data initialization
    std::vector<std::pair<Resource, std::pair<int, std::size_t>>> plotData = {
        {Resource::WOOD, {10, 0}}, {Resource::BRICK, {2, 1}}, {Resource::WOOL, {9, 2}}, {Resource::WHEAT, {12, 3}},
        {Resource::IRON, {6, 4}}, {Resource::BRICK, {4, 5}}, {Resource::IRON, {10, 6}}, {Resource::WHEAT, {9, 7}},
        {Resource::WOOL, {11, 8}}, {Resource::DESERT, {7, 9}}, {Resource::WOOL, {3, 10}}, {Resource::WOOD, {8, 11}},
        {Resource::WOOL, {8, 12}}, {Resource::WOOD, {3, 13}}, {Resource::WHEAT, {4, 14}}, {Resource::BRICK, {5, 15}},
        {Resource::IRON, {5, 16}}, {Resource::WHEAT, {6, 17}}, {Resource::BRICK, {11, 18}}
    };

    // Initialize plots
    for (std::vector<std::pair<Resource, std::pair<int, std::size_t>>>::size_type i = 0; i < plotData.size(); ++i) {
        plots.emplace_back(Plot(std::get<0>(plotData[i]), std::get<1>(plotData[i]).first, std::get<1>(plotData[i]).second));
    }

    // Initialize vertices
    vertices.reserve(54);
    for (std::size_t i = 0; i < 54; ++i)
    {
        vertices.emplace_back(Vertex(i));
    }

    // Vertex mappings initialization
    std::vector<std::vector<std::size_t>> vertexMapping = {
        {0, 1, 31, 30, 28, 29}, {2, 3, 33, 32, 31, 1}, {4, 5, 6, 34, 33, 3},
        {28, 30, 47, 46, 26, 27}, {31, 32, 49, 48, 47, 30}, {33, 34, 35, 50, 49, 32},
        {6, 7, 8, 36, 35, 34}, {26, 46, 45, 23, 24, 25}, {47, 48, 53, 44, 45, 46},
        {49, 50, 54, 52, 53, 48}, {35, 36, 37, 38, 54, 50}, {8, 9, 10, 11, 37, 36},
        {45, 44, 43, 21, 22, 23}, {53, 52, 41, 42, 43, 44}, {54, 38, 39, 40, 41, 52},
        {37, 11, 12, 13, 39, 38}, {43, 42, 18, 19, 20, 21}, {41, 40, 16, 17, 18, 42},
        {39, 13, 14, 15, 16, 40}
    };
    
    // Assign vertices to plots
    for (std::size_t i = 0; i < 19; i++) {
        for (std::size_t j = 0; j < 6; j++) {
            plots[i].setVertex(&vertices[vertexMapping[i][j]]);
        }
    } 

    // Initialize vertex neighbors
    vertices[0].addNeighbor(&vertices[1]);
    vertices[0].addNeighbor(&vertices[29]);
    vertices[1].addNeighbor(&vertices[0]);
    vertices[1].addNeighbor(&vertices[2]);
    vertices[2].addNeighbor(&vertices[1]);
    vertices[2].addNeighbor(&vertices[3]);
    vertices[2].addNeighbor(&vertices[1]);
    vertices[3].addNeighbor(&vertices[2]);
    vertices[3].addNeighbor(&vertices[4]);
    vertices[4].addNeighbor(&vertices[3]);
    vertices[4].addNeighbor(&vertices[5]);
    vertices[5].addNeighbor(&vertices[5]);
    vertices[5].addNeighbor(&vertices[6]);
    vertices[6].addNeighbor(&vertices[5]);
    vertices[6].addNeighbor(&vertices[7]);
    vertices[6].addNeighbor(&vertices[34]);
    vertices[7].addNeighbor(&vertices[6]);
    vertices[7].addNeighbor(&vertices[8]);
    vertices[8].addNeighbor(&vertices[7]);
    vertices[8].addNeighbor(&vertices[9]);
    vertices[8].addNeighbor(&vertices[36]);
    vertices[9].addNeighbor(&vertices[8]);
    vertices[9].addNeighbor(&vertices[10]);
    vertices[10].addNeighbor(&vertices[9]);
    vertices[10].addNeighbor(&vertices[11]);
    vertices[11].addNeighbor(&vertices[10]);
    vertices[11].addNeighbor(&vertices[12]);
    vertices[11].addNeighbor(&vertices[37]);
    vertices[12].addNeighbor(&vertices[11]);
    vertices[12].addNeighbor(&vertices[13]);
    vertices[13].addNeighbor(&vertices[12]);
    vertices[13].addNeighbor(&vertices[14]);
    vertices[13].addNeighbor(&vertices[39]);
    vertices[14].addNeighbor(&vertices[13]);
    vertices[14].addNeighbor(&vertices[15]);
    vertices[15].addNeighbor(&vertices[14]);
    vertices[15].addNeighbor(&vertices[16]);
    vertices[16].addNeighbor(&vertices[15]);
    vertices[16].addNeighbor(&vertices[17]);
    vertices[16].addNeighbor(&vertices[40]);
    vertices[17].addNeighbor(&vertices[16]);
    vertices[17].addNeighbor(&vertices[16]);
    vertices[18].addNeighbor(&vertices[17]);
    vertices[18].addNeighbor(&vertices[19]);
    vertices[18].addNeighbor(&vertices[42]);
    vertices[19].addNeighbor(&vertices[18]);
    vertices[19].addNeighbor(&vertices[20]);
    vertices[20].addNeighbor(&vertices[19]);
    vertices[20].addNeighbor(&vertices[21]);
    vertices[21].addNeighbor(&vertices[20]);
    vertices[21].addNeighbor(&vertices[22]);
    vertices[21].addNeighbor(&vertices[43]);
    vertices[22].addNeighbor(&vertices[23]);
    vertices[22].addNeighbor(&vertices[21]);
    vertices[23].addNeighbor(&vertices[22]);
    vertices[23].addNeighbor(&vertices[24]);
    vertices[23].addNeighbor(&vertices[45]);
    vertices[24].addNeighbor(&vertices[23]);
    vertices[24].addNeighbor(&vertices[25]);
    vertices[25].addNeighbor(&vertices[24]);
    vertices[25].addNeighbor(&vertices[26]);
    vertices[26].addNeighbor(&vertices[25]);
    vertices[26].addNeighbor(&vertices[27]);
    vertices[26].addNeighbor(&vertices[46]);
    vertices[27].addNeighbor(&vertices[26]);
    vertices[27].addNeighbor(&vertices[28]);
    vertices[28].addNeighbor(&vertices[27]);
    vertices[28].addNeighbor(&vertices[29]);
    vertices[28].addNeighbor(&vertices[30]);
    vertices[29].addNeighbor(&vertices[28]);
    vertices[29].addNeighbor(&vertices[0]);
    vertices[30].addNeighbor(&vertices[28]);
    vertices[30].addNeighbor(&vertices[31]);
    vertices[30].addNeighbor(&vertices[47]);
    vertices[31].addNeighbor(&vertices[1]);
    vertices[31].addNeighbor(&vertices[32]);
    vertices[31].addNeighbor(&vertices[30]);
    vertices[32].addNeighbor(&vertices[31]);
    vertices[32].addNeighbor(&vertices[33]);
    vertices[32].addNeighbor(&vertices[49]);
    vertices[31].addNeighbor(&vertices[30]);
    vertices[31].addNeighbor(&vertices[20]);
    vertices[31].addNeighbor(&vertices[32]);
    vertices[32].addNeighbor(&vertices[31]);
    vertices[32].addNeighbor(&vertices[33]);
    vertices[32].addNeighbor(&vertices[49]);
    vertices[33].addNeighbor(&vertices[3]);
    vertices[33].addNeighbor(&vertices[32]);
    vertices[33].addNeighbor(&vertices[34]);
    vertices[34].addNeighbor(&vertices[33]);
    vertices[34].addNeighbor(&vertices[35]);
    vertices[34].addNeighbor(&vertices[6]);
    vertices[35].addNeighbor(&vertices[34]);
    vertices[35].addNeighbor(&vertices[36]);
    vertices[35].addNeighbor(&vertices[50]);
    vertices[36].addNeighbor(&vertices[35]);
    vertices[36].addNeighbor(&vertices[37]);
    vertices[36].addNeighbor(&vertices[8]);
    vertices[37].addNeighbor(&vertices[36]);
    vertices[37].addNeighbor(&vertices[11]);
    vertices[37].addNeighbor(&vertices[38]);
    vertices[38].addNeighbor(&vertices[37]);
    vertices[38].addNeighbor(&vertices[39]);
    vertices[38].addNeighbor(&vertices[51]);
    vertices[39].addNeighbor(&vertices[39]);
    vertices[39].addNeighbor(&vertices[40]);
    vertices[39].addNeighbor(&vertices[13]);
    vertices[40].addNeighbor(&vertices[39]);
    vertices[40].addNeighbor(&vertices[41]);
    vertices[40].addNeighbor(&vertices[16]);
    vertices[41].addNeighbor(&vertices[42]);
    vertices[41].addNeighbor(&vertices[40]);
    vertices[41].addNeighbor(&vertices[52]);
    vertices[42].addNeighbor(&vertices[41]);
    vertices[42].addNeighbor(&vertices[43]);
    vertices[42].addNeighbor(&vertices[18]);
    vertices[43].addNeighbor(&vertices[44]);
    vertices[43].addNeighbor(&vertices[42]);
    vertices[43].addNeighbor(&vertices[21]);
    vertices[44].addNeighbor(&vertices[43]);
    vertices[44].addNeighbor(&vertices[45]);
    vertices[44].addNeighbor(&vertices[53]);
    vertices[45].addNeighbor(&vertices[46]);
    vertices[45].addNeighbor(&vertices[44]);
    vertices[45].addNeighbor(&vertices[23]);
    vertices[46].addNeighbor(&vertices[45]);
    vertices[46].addNeighbor(&vertices[47]);
    vertices[46].addNeighbor(&vertices[26]);
    vertices[47].addNeighbor(&vertices[46]);
    vertices[47].addNeighbor(&vertices[48]);
    vertices[47].addNeighbor(&vertices[30]);
    vertices[48].addNeighbor(&vertices[47]);
    vertices[48].addNeighbor(&vertices[49]);
    vertices[48].addNeighbor(&vertices[53]);
    vertices[49].addNeighbor(&vertices[50]);
    vertices[49].addNeighbor(&vertices[48]);
    vertices[49].addNeighbor(&vertices[32]);
    vertices[50].addNeighbor(&vertices[49]);
    vertices[50].addNeighbor(&vertices[51]);
    vertices[50].addNeighbor(&vertices[35]);
    vertices[51].addNeighbor(&vertices[50]);
    vertices[51].addNeighbor(&vertices[52]);
    vertices[51].addNeighbor(&vertices[38]);
    vertices[52].addNeighbor(&vertices[53]);
    vertices[52].addNeighbor(&vertices[51]);
    vertices[52].addNeighbor(&vertices[41]);
    vertices[53].addNeighbor(&vertices[52]);
    vertices[53].addNeighbor(&vertices[44]);
    vertices[53].addNeighbor(&vertices[48]);

    // Initialize edges
    edges.reserve(72);
    for (std::size_t i = 0; i < 72; ++i)
    {
        edges.emplace_back(Edge(i));
    }

// Edge mappings initialization
std::vector<std::vector<std::size_t>> edgeMapping = {
    {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {0, 8}, {2, 10}, {4, 12}, {6, 14}, {7, 8}, {8, 9}, {9, 10}, {10, 11}, {11, 12}, {12, 13}, {13, 14}, {14, 15}, {7, 17}, {9, 19}, {11, 21}, {13, 23}, {15, 25}, {16, 17}, {17, 18}, {18, 19}, {19, 20}, {20, 21}, {21, 22}, {22, 23}, {23, 24}, {24, 25}, {25, 26}, {16, 27}, {18, 29}, {20, 31}, {22, 33}, {24, 35}, {26, 37}, {27, 28}, {28, 29}, {29, 30}, {30, 31}, {31, 32}, {32, 33}, {33, 34}, {34, 35}, {35, 36}, {36, 37}, {28, 38}, {30, 40}, {32, 42}, {34, 44}, {36, 46}, {38, 39}, {39, 40}, {40, 41}, {41, 42}, {42, 43}, {43, 44}, {44, 45}, {45, 46}, {39, 47}, {41, 49}, {43, 51}, {45, 53}, {47, 48}, {48, 49}, {49, 50}, {50, 51}, {51, 52}, {52, 53}
};

// Assign vertices to edges and edges to vertices
for (std::size_t i = 0; i < edges.size(); ++i)
{
    edges[i].setVertices(&vertices[edgeMapping[i][0]], &vertices[edgeMapping[i][1]]);
    vertices[edgeMapping[i][0]].addEdge(&edges[i]);
    vertices[edgeMapping[i][1]].addEdge(&edges[i]);
}

// Initialize development cards
for (int i = 0; i < 14; i++)
{
    developmentCards.push_back(DevelopmentCard("Knight"));
}
for (int i = 0; i < 5; i++)
{
    developmentCards.push_back(DevelopmentCard("Victory Point"));
}
for (int i = 0; i < 2; i++)
{
    developmentCards.push_back(DevelopmentCard("Road Placement"));
}
for (int i = 0; i < 2; i++)
{
    developmentCards.push_back(DevelopmentCard("Year Of Plenty"));
}
for (int i = 0; i < 2; i++)
{
    developmentCards.push_back(DevelopmentCard("Monopoly"));
}

// Shuffle development cards
std::random_shuffle(developmentCards.begin(), developmentCards.end());

// Print initial board setup message
std::cout << "Game setup is complete. Initial board configuration:" << std::endl;
printBoard();
}


const std::vector<Plot> &Board::getPlots() const
{
    return plots;
}

std::vector<Vertex> &Board::getVertices()
{
    return vertices;
}

std::vector<Edge> &Board::getEdges()
{
    return edges;
}

int Board::getEdge(std::size_t vertexIndex1, std::size_t vertexIndex2) {
    if (vertexIndex1 > vertexIndex2) {
        std::swap(vertexIndex1, vertexIndex2);
    }
    for (std::size_t i = 0; i < edges.size(); ++i) {
        if (edges[i].getVertex1()->getId() == vertexIndex1 && edges[i].getVertex2()->getId() == vertexIndex2) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void Board::giveResources(std::vector<Player*>& players, int diceRoll) {
    for (auto& plot : plots) {
        if (plot.getNumber() == diceRoll) {
            for (auto& vertex : plot.getVertices()) {
                int owner = vertex->getOwner();
                if (owner != -1) {
                    if (owner < 0 || static_cast<std::vector<Player*>::size_type>(owner) >= players.size()) {
                        throw std::out_of_range("Invalid owner ID");
                    }

                    Resource resource = plot.getResource();
                    int amount = (vertex->getCity().empty()) ? 1 : 2;
                    std::string resourceString = resourceToString(resource);
                    players[static_cast<std::vector<Player*>::size_type>(owner)]->addResource(stringToResource(resourceString), amount);
                }
            }
        }
    }
}


void Board::drawDevelopmentCard(int playerId) {
    if (playerId <= 0 || static_cast<std::vector<Player*>::size_type>(playerId - 1) >= players.size()) {
        throw std::out_of_range("Invalid player ID");
    }

    players[static_cast<std::vector<Player *>::size_type>(playerId - 1)]->getDevelopmentCards().push_back(developmentCards[0].getType());
    developmentCards.erase(developmentCards.begin());
}

bool Board::canPlaceInitialSettlement(Player &player, std::size_t vertexIndex) {
    if (vertexIndex >= vertices.size()) {
        std::cerr << "Invalid vertex index." << std::endl;
        return false;
    }

    Vertex &vertex1 = vertices[vertexIndex];

    if (vertex1.getOwner() != -1) {
        std::cerr << "This vertex is already occupied." << std::endl;
        return false;
    }

    for (const Vertex *neighbor : vertex1.getNeighbors()) {
        if (neighbor->getOwner() != -1) {
            std::cerr << "Adjacent vertex " << neighbor->getId() << " already occupied." << std::endl;
            return false;
        }
    }


    vertex1.setOwner(player.getId());
    // Grant resources for the initial settlement placement
    for (auto &plot : plots) {
       for (auto &vertex : plot.getVertices()) {
          if (size_t(vertex->getId()) == vertexIndex) {
            player.addResource(stringToResource(resourceToString(plot.getResource())), 1);
            
          }
        }
    }
    std::cout << "Player " << player.getName() << " now has resources: ";
                for (const auto& resource : player.getResources()) {
                    std::cout << resource.first << ": " << resource.second << ", ";
                }

    return true;
}

bool Board::canPlaceInitialRoad(Player &player, std::size_t vertexIndex, std::size_t vertexIndex2) {
    if (vertexIndex >= vertices.size() || vertexIndex2 >= vertices.size()) {
        std::cerr << "Invalid vertex index." << std::endl;
        return false;
    }

    Vertex &vertex1 = vertices[vertexIndex];
    Vertex &vertex2 = vertices[vertexIndex2];

    
    if (!vertex1.isNeighbor(vertex2)) {
        std::cerr << "Vertices are not neighbors." << std::endl;
        return false;
    }
    
    int edgeIndex = getEdge(vertexIndex, vertexIndex2);
    if (edgeIndex != -1 && edges[std::size_t(edgeIndex)].getOwner() != -1) {
        std::cerr << "Edge is already occupied." << std::endl;
        return false;
    }

    edges[std::size_t(edgeIndex)].setOwner(player.getId());
    return true;
}

bool Board::canPlaceSettlement(int playerId, std::size_t vertexIndex)
{
    if (vertexIndex >= vertices.size() || vertexIndex < 0)
    {
        std::cerr << "Invalid vertex index." << std::endl;
        return false;
    }

    Vertex &vertex = vertices[vertexIndex];

    if (vertex.getOwner() != -1)
    {
        std::cerr << "Vertex is already occupied." << std::endl;
        return false;
    }
    const std::vector<Vertex *> &adjacentPlots = vertex.getNeighbors();
    for (const Vertex *adjacentVertex : adjacentPlots)
    {
        if (adjacentVertex->getOwner() != -1)
        {
            std::cerr << "Adjacent vertex" << adjacentVertex->getId() << "already occupied." << std::endl;
            return false;
        }
    }

    const std::vector<Edge *> &adjacentEdges = vertex.getEdges();

    for (const Edge *edge : adjacentEdges)
    {
        if (edge->getOwner() == playerId)
        {
            vertex.setOwner(playerId);
            return true;
        }
    }
    std::cerr << "No adjacent edges belong to the player." << std::endl;
    return false;
}

bool Board::canPlaceRoad(int playerId, std::size_t vertexIndex1, std::size_t vertexIndex2)
{
    if (vertexIndex1 >= vertices.size() || vertexIndex2 >= vertices.size() || vertexIndex1 == vertexIndex2 || vertexIndex1 < 0 || vertexIndex2 < 0)
    {
        std::cerr << "Invalid vertex indices." << std::endl;
        return false;
    }

    const Vertex &v1 = vertices[vertexIndex1];
    const Vertex &v2 = vertices[vertexIndex2];

    if (!v1.isNeighbor(v2))
    {
        std::cerr << "Vertices are not neighbors." << std::endl;
        return false;
    }

    const std::vector<Edge *> &adjacentEdges1 = v1.getEdges();
    const std::vector<Edge *> &adjacentEdges2 = v2.getEdges();
    for (const Edge *edge1 : adjacentEdges1)
    {
        for (const Edge *edge2 : adjacentEdges2)
        {
            if (edge1 == edge2 && edge1->getOwner() != -1)
            {
                std::cerr << "Road is already occupied." << std::endl;
                return false;
            }
        }
    }

    if (v1.getOwner() == playerId || v2.getOwner() == playerId)
    {
        int edgeIndex = getEdge(vertexIndex1, vertexIndex2);
        if (edgeIndex != -1)
        {
            edges[size_t(edgeIndex)].setOwner(playerId);
        }
        return true;
    }

    for (const Edge *edge1 : adjacentEdges1)
    {
        for (const Edge *edge2 : adjacentEdges2)
        {
            if (edge1->getOwner() == playerId || edge2->getOwner() == playerId)
            {
                int edgeIndex = getEdge(vertexIndex1, vertexIndex2);
                if (edgeIndex != -1)
                {
                    edges[size_t(edgeIndex)].setOwner(playerId);
                    return true;
                }
            }
        }
    }
    return false;
}

bool Board::canPlaceCity(int playerId, std::size_t vertexIndex)
{
    if (vertexIndex >= vertices.size() || vertexIndex < 0)
    {
        std::cerr << "Invalid vertex index." << std::endl;
        return false;
    }

    Vertex &vertex = vertices[vertexIndex];

    if (vertex.getOwner() != playerId)
    {
        std::cerr << "Vertex is not occupied by the player." << std::endl;
        return false;
    }

    if (vertex.getCity() == "") 
    {
        std::cerr << "Vertex is already occupied by a city." << std::endl;
        return false;
    }
    vertex.setCity("1");
    return true;
}

void Board::printBoard()
{
    for (const Plot &plot : plots)
    {
        std::cout << "Plot " << plot.getIndex() << ": " << plot.getResource() << " (" << plot.getNumber() << ")\n";
    }
}

void Board::placeSettlement(const std::string& place, int placeNum, Player* player) {
    Resource resource = stringToResource(place);
    for (auto& vertex : vertices) {
        if (vertex.getCity() == place && vertex.getOwner() == -1) {
            vertex.setOwner(player->getId());
            player->addResource(resource, placeNum);
        }
    }
}
Player& Board::getPlayerById(int playerId) {
    if(size_t(playerId) > this->players.size()){
        throw std::out_of_range("Invalid player ID");
    }
    return *players[size_t(playerId-1)];
}

void Board::printWinner() const {
    for (const Player* player : players) {
        if (player->isWinner()) {
            std::cout << player->getName() << " is the winner!" << std::endl;
            return;
        }
    }
    std::cout << "No winner yet." << std::endl;
}
