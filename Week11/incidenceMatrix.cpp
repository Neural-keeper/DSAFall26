// incidence matrix
// very rarely used
// just giving code for reference but
// please don't use this, there's only some use cases and you won't be in those scenarios for a while yet

#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    vector<vector<int>> incidenceMatrix;
    int numVertices;
    int numEdges;

public:
    // Initialize graph with given number of vertices and edges
    Graph(int vertices, int edges) {
        numVertices = vertices;
        numEdges = edges;
        incidenceMatrix = vector<vector<int>>(vertices, vector<int>(edges, 0));
    }

    ~Graph() {
        // No dynamic memory to free in this implementation
    }

    // Add an edge between vertices u and v
    void AddEdge(int u, int v, int edgeIndex) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices && edgeIndex >= 0 && edgeIndex < numEdges) {
            incidenceMatrix[u][edgeIndex] = 1; // u is incident to the edge
            incidenceMatrix[v][edgeIndex] = 1; // v is incident to the edge
        }
    }

    // Remove an edge between vertices u and v
    void RemoveEdge(int u, int v, int edgeIndex) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices && edgeIndex >= 0 && edgeIndex < numEdges) {
            incidenceMatrix[u][edgeIndex] = 0; // u is no longer incident to the edge
            incidenceMatrix[v][edgeIndex] = 0; // v is no longer incident to the edge
        }
    }

    void AddVertex() {
        numVertices++;
        incidenceMatrix.push_back(vector<int>(numEdges, 0)); // Add a new row for the new vertex
    }

    void RemoveVertex(int v) {
        if (v >= 0 && v < numVertices) {
            incidenceMatrix.erase(incidenceMatrix.begin() + v); // Remove the row
            numVertices--;
        }
    }

    // Print the incidence matrix
    void PrintGraph() {
        cout << "Incidence Matrix:" << endl;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numEdges; j++) {
                cout << incidenceMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 4 vertices and 4 edges
    Graph g(4, 4);

    // Add edges
    g.AddEdge(0, 1, 0);
    g.AddEdge(1, 2, 1);
    g.AddEdge(2, 3, 2);
    g.AddEdge(3, 0, 3);

    // Print initial graph
    cout << "Initial graph:" << endl;
    g.PrintGraph();

    // Remove an edge and print the graph again
    cout << "\nRemoving edge between 1 and 2 (edge index 1)..." << endl;
    g.RemoveEdge(1, 2, 1);
    g.PrintGraph();

    // Add a vertex and print the graph again
    cout << "\nAdding a new vertex..." << endl;
    g.AddVertex();
    g.PrintGraph();

    // Remove a vertex and print the graph again
    cout << "\nRemoving vertex 2..." << endl;
    g.RemoveVertex(2);
    g.PrintGraph();

    return 0;
}