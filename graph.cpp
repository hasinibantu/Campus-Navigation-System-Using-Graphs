#include "Graph.h"
#include <algorithm>
#include <climits>

// Constructor
Graph::Graph()
{
    // Initially empty
}
// Add a new building
void Graph::addBuilding(int id, string name, bool showMessage)
{
    Building newBuilding(id, name);

    buildings.push_back(newBuilding);
    adjList.push_back(vector<pair<int, int>>());

    if(showMessage)
        cout << "\nBuilding added successfully!\n";
}

// Display all buildings
void Graph::displayBuildings()
{
    if (buildings.empty())
    {
        cout << "\nNo buildings available.\n";
        return;
    }

    cout << "\n===== CAMPUS BUILDINGS =====\n";

    for (int i = 0; i < buildings.size(); i++)
    {
        buildings[i].display();
        cout << "--------------------------\n";
    }
}
// Find building index by ID
int Graph::findBuildingById(int id)
{
    for (int i = 0; i < buildings.size(); i++)
    {
        if (buildings[i].getId() == id)
        {
            return i;
        }
    }

    return -1;
}
// Connect two buildings
void Graph::addRoad(int source, int destination, int distance, bool showMessage)
{
    int srcIndex = findBuildingById(source);
    int destIndex = findBuildingById(destination);

    if (srcIndex == -1 || destIndex == -1)
    {
        cout << "\nInvalid Building ID!\n";
        return;
    }

    // Since roads are two-way
    adjList[srcIndex].push_back({destIndex, distance});
    adjList[destIndex].push_back({srcIndex, distance});

    if(showMessage)
        cout << "\nRoad added successfully!\n";
}
// Display Graph
void Graph::displayMap()
{
    if (buildings.empty())
    {
        cout << "\nNo buildings found.\n";
        return;
    }

    cout << "\n========== CAMPUS MAP ==========\n";

    for (int i = 0; i < buildings.size(); i++)
    {
        cout << buildings[i].getName() << " --> ";

        for (auto road : adjList[i])
        {
            cout << "("
                 << buildings[road.first].getName()
                 << ", "
                 << road.second
                 << " m) ";
        }

        cout << endl;
    }
}

void Graph::DFS(int start)
{
    int startIndex = findBuildingById(start);

    if (startIndex == -1)
    {
        cout << "\nInvalid Building ID!\n";
        return;
    }

    vector<bool> visited(buildings.size(), false);
    stack<int> s;

    s.push(startIndex);

    cout << "\n===== DFS Traversal =====\n";

    while (!s.empty())
    {
        int current = s.top();
        s.pop();

        if (!visited[current])
        {
            visited[current] = true;
            cout << buildings[current].getName() << endl;

            for (int i = adjList[current].size() - 1; i >= 0; i--)
            {
                int next = adjList[current][i].first;

                if (!visited[next])
                {
                    s.push(next);
                }
            }
        }
    }
}
// Breadth First Search
void Graph::BFS(int start)
{
    int startIndex = findBuildingById(start);

    if (startIndex == -1)
    {
        cout << "\nInvalid Building ID!\n";
        return;
    }

    vector<bool> visited(buildings.size(), false);
    queue<int> q;

    visited[startIndex] = true;
    q.push(startIndex);

    cout << "\n===== BFS Traversal =====\n";

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        cout << buildings[current].getName() << endl;

        for (auto road : adjList[current])
        {
            int next = road.first;

            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}
// Dijkstra's Shortest Path Algorithm
void Graph::shortestPath(int source, int destination)
{
    int src = findBuildingById(source);
    int dest = findBuildingById(destination);

    if (src == -1 || dest == -1)
    {
        cout << "\nInvalid Building ID!\n";
        return;
    }

    int n = buildings.size();

    vector<int> distance(n, INT_MAX);
    vector<int> parent(n, -1);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    distance[src] = 0;
    pq.push({0, src});

    while(!pq.empty())
    {
        int current = pq.top().second;
        pq.pop();

        for(auto road : adjList[current])
        {
            int next = road.first;
            int weight = road.second;

            if(distance[current] + weight < distance[next])
            {
                distance[next] = distance[current] + weight;
                parent[next] = current;
                pq.push({distance[next], next});
            }
        }
    }

    if(distance[dest] == INT_MAX)
    {
        cout << "\nNo path found!\n";
        return;
    }

    vector<int> path;

    for(int v = dest; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    cout << "\n===== SHORTEST PATH =====\n";

    for(int i = 0; i < path.size(); i++)
    {
        cout << buildings[path[i]].getName();

        if(i != path.size()-1)
            cout << " -> ";
    }

    cout << "\n\nTotal Distance : "
         << distance[dest]
         << " meters\n";
}
vector<Building>& Graph::getBuildings()
{
    return buildings;
}

vector<vector<pair<int,int>>>& Graph::getAdjList()
{
    return adjList;
}

void Graph::searchBuilding(int id)
{
    int index = findBuildingById(id);

    if(index==-1)
    {
        cout<<"\nBuilding not found.\n";
        return;
    }

    cout<<"\n===== BUILDING DETAILS =====\n";

    buildings[index].display();
}
