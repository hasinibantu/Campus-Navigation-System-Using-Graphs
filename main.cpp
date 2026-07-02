#include <iostream>
#include "Graph.h"
#include "FileManager.h"

using namespace std;

int main()
{
    Graph campus;
    FileManager::loadBuildings(campus);
FileManager::loadRoads(campus);
// ===== Startup Screen =====
    cout << "============================================================\n";
    cout << "          CAMPUS NAVIGATION SYSTEM USING GRAPHS\n";
    cout << "                     Version 1.0.0\n";
    cout << "------------------------------------------------------------\n";
    cout << "        Summer Project 2025-2026\n";
    cout << " Department of Computer Science and Engineering\n";
    cout << "     Vardhaman College of Engineering\n";
    cout << "============================================================\n\n";

    cout << "Campus data loaded successfully.\n";
    cout << "Buildings and roads are ready.\n\n";
    int choice;

    do
    {
        cout << "\n============================================================\n";
        cout << "          CAMPUS NAVIGATION SYSTEM USING GRAPHS\n";
        cout << "             Vardhaman College of Engineering\n";
        cout << "============================================================\n";

      
       
        cout << "1. Display Buildings\n";
        cout << "2. Display Campus Map\n";
        cout<<"3. BFS Traversal\n";
        cout<<"4. DFS Traversal\n";
        cout<<"5. Find Shortest Path\n";
        cout<<"6. Save Campus Data\n";
        cout<<"7. Search Building\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            

            case 1:
                campus.displayBuildings();
                break;

            case 2:
                campus.displayMap();
                break;

             case 3:
               {
            int start;

             cout << "Enter Starting Building ID: ";
            cin >> start;

            campus.BFS(start);
           break;
             }

            case 4:
            {
               int start;

              cout<<"Enter Starting Building ID: ";
               cin>>start;

               campus.DFS(start);

              break;
        }
        case 5:
        {
    int source, destination;

    cout << "Enter Source Building ID: ";
    cin >> source;

    cout << "Enter Destination Building ID: ";
    cin >> destination;

    campus.shortestPath(source, destination);
    break;
           }
            case 6:
{
    FileManager::saveBuildings(campus);
    FileManager::saveRoads(campus);
    break;
}
case 7:
{
    int id;

    cout<<"Enter Building ID: ";
    cin>>id;

    campus.searchBuilding(id);

    break;
}

            case 0:
                cout << "\nThank you for using Campus Navigation System!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while(choice != 0);

    return 0;
}