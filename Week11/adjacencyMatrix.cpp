#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjacencyMatrix;
    int numVertices;

public:
    // Initialize graph with given number of vertices
    Graph(int vertices) {
        numVertices = vertices;
        adjacencyMatrix = vector<vector<int>>(vertices, vector<int>(vertices, 0));
    }

    // Add an edge between vertices u and v
    void AddEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjacencyMatrix[u][v] = 1;
            adjacencyMatrix[v][u] = 1;  // For undirected graph
        }
    }

    // Remove an edge between vertices u and v
    void RemoveEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjacencyMatrix[u][v] = 0;
            adjacencyMatrix[v][u] = 0;  // For undirected graph
        }
    }

    // Check if vertices u and v are adjacent
    bool IsAdjacent(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            return adjacencyMatrix[u][v] == 1;
        }
        return false;
    }

    // Get neighbors of vertex v
    vector<int> GetNeighbors(int v) {
        vector<int> neighbors;
        if (v >= 0 && v < numVertices) {
            for (int i = 0; i < numVertices; i++) {
                if (adjacencyMatrix[v][i] == 1) {
                    neighbors.push_back(i);
                }
            }
        }
        return neighbors;
    }

    // Get the edge list of the graph
    vector<pair<int, int>> GetEdgeList() {
        vector<pair<int, int>> edges;
        for (int i = 0; i < numVertices; i++) {
            for (int j = i + 1; j < numVertices; j++) {  // j starts from i+1 to avoid duplicates
                if (adjacencyMatrix[i][j] == 1) {
                    edges.push_back({i, j});
                }
            }
        }
        return edges;
    }

    // Get the adjacency matrix of the graph
    vector<vector<int>> GetAdjacencyMatrix() {
        return adjacencyMatrix;
    }

    // Print the adjacency matrix
    void PrintGraph() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 4 vertices
    Graph g(4);

    // Add edges
    g.AddEdge(0, 1);
    g.AddEdge(1, 2);
    g.AddEdge(2, 3);
    g.AddEdge(3, 0);

    // Print initial graph
    cout << "Initial graph:" << endl;
    g.PrintGraph();

    // Test adjacency
    cout << "\nIs 0 adjacent to 1? " << g.IsAdjacent(0, 1) << endl;
    cout << "Is 1 adjacent to 3? " << g.IsAdjacent(1, 3) << endl;

    // Get and print neighbors
    cout << "\nNeighbors of vertex 2:" << endl;
    vector<int> neighbors = g.GetNeighbors(2);
    for (int neighbor : neighbors) {
        cout << neighbor << " ";
    }
    cout << endl;

    // Get and print edge list
    cout << "\nEdge List:" << endl;
    vector<pair<int, int>> edges = g.GetEdgeList();
    for (const auto& edge : edges) {
        cout << "(" << edge.first << ", " << edge.second << ")" << endl;
    }

    // Get and print adjacency matrix
    cout << "\nAdjacency Matrix:" << endl;
    vector<vector<int>> matrix = g.GetAdjacencyMatrix();
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Remove an edge and print again
    g.RemoveEdge(1, 2);
    cout << "\nGraph after removing edge (1,2):" << endl;
    g.PrintGraph();

    return 0;
}