// Still graphs
/*
I want to do a bit more of a real problem
this is something where we need to 
1) decide the representation of the graph
2) implement the graph
To keep this snappy, we'll do interview style, where we don't need to implement a generic graph
So we can just use the vector directly, and we can just use int for the vertex type
In the future, we will perform actual searches or algorithms on it
Things like "find the number of islands" or "find the shortest path" or "find the minimum spanning tree"
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// CONTEXT 1
/*
You work for a tour guide company (in the world of Arendil, no I will not shut up). One day, your boss asks you
to make a map of a new town that's finally open to visitors after centuries of being closed off.
He tells you he send a group of scouts to make a map of the town, but all they did was note down two things:
1) the number of landmark establishments (bookstore, tavern, etc) in the town
2) the distance between two adjacent ones that shared a street (no path passes another establishment to get to its destination)
He also tells you there were 5 establishments, and 10 "distances" measured.

Your job is to take this information and quickly create a graph representation of the town, so that you can later use it to find the shortest path between two establishments, or to find the minimum spanning tree of the town.
*/

struct Distance {
    string town1;
    string town2;
    int distance;
};

// SOLUTION 1
void townGraph(vector<string> landmarks, vector<Distance> distances) {
    // insert graph representation here, goal is to print it out
    // let's make an adjacency list (10 < 5^2 (25))
    unordered_map<string, vector<pair<string, int>>> adjList;

    // initialize my adjList with every landmark
    for (const string& landmark : landmarks) {
        adjList[landmark] = {}; // initialize with empty vector/array
    }

    // find neighbours for each landmark
    for (const Distance& edge : distances) {
        string t1 = edge.town1;
        string t2 = edge.town2;
        int dist = edge.distance;
        adjList[t1].push_back({t2, dist});
        adjList[t2].push_back({t1, dist});
    } // populate adjList

    // print adjacency list
    for (const auto& [town, neighbors] : adjList) {
        cout << town << " is adjacent to: ";
        for (const auto& [neighborName, dist] : neighbors) {
            cout << neighborName << " (" << dist << ") | ";
        }
        cout << endl;
    }
}

int main() {
    vector<string> landmarks = {"Bookstore", "Tavern", "Bakery", "Inn", "Blacksmith"};
    vector<Distance> distances = {
        {"Bookstore", "Tavern", 5},
        {"Bookstore", "Bakery", 3},
        {"Tavern", "Inn", 4},
        {"Bakery", "Inn", 2},
        {"Bakery", "Blacksmith", 6},
        {"Inn", "Blacksmith", 1},
        {"Tavern", "Blacksmith", 7},
        {"Bookstore", "Inn", 8},
        {"Tavern", "Bakery", 9},
        {"Inn", "Bakery", 10}
    };

    /*
    Bookstore: Tavern (5) | Bakery (3) | Inn (8) 
    Tavern: Bookstore (5) | Inn (4) | Blacksmith (7) | Bakery (9)
    Bakery: Bookstore (3) | 
    */

    townGraph(landmarks, distances);

    return 0;
}