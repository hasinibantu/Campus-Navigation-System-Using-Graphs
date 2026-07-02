#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

class FileManager
{
public:
    static void saveBuildings(Graph &campus);
    static void saveRoads(Graph &campus);

    static void loadBuildings(Graph &campus);
    static void loadRoads(Graph &campus);
};

#endif