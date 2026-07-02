#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <climits>
#include <algorithm>

#include "Building.h"

using namespace std;

class Graph
{
private:
    vector<Building> buildings;
    vector<vector<pair<int,int>>> adjList;

public:

    Graph();

    // Building Operations
   void addBuilding(int id, string name, bool showMessage = true);
    void displayBuildings();
    int findBuildingById(int id);

    // Road Operations
  void addRoad(int source, int destination, int distance, bool showMessage = true);
    void displayMap();

    // Graph Algorithms
    void BFS(int start);
    void DFS(int start);
    void shortestPath(int source,int destination);

    // Search
    void searchBuilding(int id);

    // File Handling Helpers
    vector<Building>& getBuildings();
    vector<vector<pair<int,int>>>& getAdjList();
};

#endif