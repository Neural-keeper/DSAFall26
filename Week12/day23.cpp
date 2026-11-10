// graph traversals 
#include <iostream>
#include <vector>
#include <queue> // for BFS

using namespace std;

// Depth-First Search 
// recursively (call stack), use a LIFO data structure
//   visits every vertex and edge in a graph G
//   it can determine if a graph G is connected
//   computes spanning forest
//   find a path between 2 given vertices
//   find a cycle
//   solve mazes (or things with a single solution)
// when using adjacency list representation of graph, O(m + n)

// dfs, prints path that it took, takes
// 1 starting point
// 2 adjacency list graph
// 3 keep track of what's been visited
void dfs(int vertex, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[vertex] = true; // set current point as visited since we got here
    cout << vertex << " "; // print traversal "we've been here"

    for(int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited); // using recusion (call stack)
        }
    }
}


// Breadth-first Search
// iterative, use queue (FIFO)
//   visits every vertex and edge
//   can determine if G is connected
//   compute a spanning forest
//   find minimum path (or path with minimum number of edges) between two vertices
//   find a simple cycle
// when using adjacency list representation of graph, O(m + n)

// bfs, prints path that it took, takes
// 1 starting point
// 2 adjacency list graph
void bfs(int startVertex, vector<vector<int>>& graph) {
    vector<int> visited(graph.size(), false);
    queue<int> q;

    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        cout << vertex << " "; // prints traversal

        for (int neighbor : graph[vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

/*

0 -- 2
  \
    1 --- 3
      \
       4
*/

// testing
int main() {
    // making my adjacency list graph
    vector<vector<int>> graph = {
        {1, 2},      // neighbors of vertex 0
        {0, 3, 4},   // neighbors of vertex 1
        {0},         // neighbors of vertex 2
        {1},         // neighbors of vertex 3
        {1}          // neighbors of vertex 4
    };

    cout << "DFS Traversal, starting from 0: ";
    vector<bool> visited(graph.size(), false); // set up visited
    dfs(0, graph, visited);
    cout << endl;

    cout << "BFS Traversal, starting from 0: ";
    bfs(0, graph);
    cout << endl;

    return 0;
}