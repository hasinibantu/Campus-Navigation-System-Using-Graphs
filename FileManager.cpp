#include "FileManager.h"

// Save Buildings
void FileManager::saveBuildings(Graph &campus)
{
    ofstream fout("buildings.txt");

    vector<Building> &buildings = campus.getBuildings();

    for(auto &b : buildings)
    {
        fout << b.getId() << "," << b.getName() << endl;
    }

    fout.close();

    cout << "\nBuildings saved successfully.\n";
}

// Save Roads
void FileManager::saveRoads(Graph &campus)
{
    ofstream fout("roads.txt");

    auto &adj = campus.getAdjList();
    auto &buildings = campus.getBuildings();

    for(int i=0;i<adj.size();i++)
    {
        for(auto road : adj[i])
        {
            if(i < road.first)
            {
                fout
                << buildings[i].getId() << " "
                << buildings[road.first].getId() << " "
                << road.second << endl;
            }
        }
    }

    fout.close();

    cout << "\nRoads saved successfully.\n";
}

// Load Buildings
void FileManager::loadBuildings(Graph &campus)
{
    ifstream fin("buildings.txt");

    if(!fin)
        return;

    int id;
    string name;

    while(fin >> id)
    {
        fin.ignore();

        getline(fin,name);

       campus.addBuilding(id, name, false);
    }

    fin.close();
}

// Load Roads
void FileManager::loadRoads(Graph &campus)
{
    ifstream fin("roads.txt");

    if(!fin)
        return;

    int s,d,dist;

    while(fin>>s>>d>>dist)
    {
        campus.addRoad(s, d, dist, false);
    }

    fin.close();
}