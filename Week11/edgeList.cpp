// genuinely one of my favorite representations to write
#include <iostream>
#include <vector>

using namespace std;

// we will only be caring about the edges as objects here
class Edge {
private:
    int vertex1;
    int vertex2;
public:
    Edge(int v1, int v2) : vertex1(v1), vertex2(v2) {}

    int getVertex1() const { return vertex1; }
    int getVertex2() const { return vertex2; }
};

class Graph {
private:
    vector<Edge> edges;
    int numVertices; // adding or removing vertices is just, removing one from this
    // then remove the edges with said vertex

public:
    Graph(int vertices) : numVertices(vertices) {}

    ~Graph() {
        // No dynamic memory to free in this implementation
    }

    // Add an edge between vertices u and v
    void AddEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            edges.push_back(Edge(u, v));
        }
    } 

    // Remove an edge between vertices u and v
    void RemoveEdge(int u, int v) {
        for (auto it = edges.begin(); it != edges.end(); ++it) {
            if ((it->getVertex1() == u && it->getVertex2() == v) || (it->getVertex1() == v && it->getVertex2() == u)) {
                edges.erase(it);
                break;
            }
        }
    }

    void AddVertex() {
        numVertices++;
    }

    void RemoveVertex(int v) {
        if (v >= 0 && v < numVertices) {
            // Remove edges associated with the vertex
            for (auto it = edges.begin(); it != edges.end();) {
                if (it->getVertex1() == v || it->getVertex2() == v) {
                    it = edges.erase(it);
                } else {
                    ++it;
                }
            }
            numVertices--;
        }
    }

    // Check if vertices u and v are adjacent
    bool IsAdjacent(int u, int v) {
        for (const Edge& edge : edges) {
            if ((edge.getVertex1() == u && edge.getVertex2() == v) || (edge.getVertex1() == v && edge.getVertex2() == u)) {
                return true;
            }
        }
        return false;
    }

    // Get neighbors of vertex v
    vector<int> GetNeighbors(int v) {
        vector<int> neighbors;
        for (const Edge& edge : edges) {
            if (edge.getVertex1() == v) {
                neighbors.push_back(edge.getVertex2());
            } else if (edge.getVertex2() == v) {
                neighbors.push_back(edge.getVertex1());
            }
        }
        return neighbors;
    }

    // print the edge list of the graph
    void PrintGraph() {    
        cout << "Edge List:" << endl;
        for (const Edge& edge : edges) {
            cout << "(" << edge.getVertex1() << ", " << edge.getVertex2() << ")" << endl;
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

    // Remove an edge and print the graph again
    cout << "\nRemoving edge between 1 and 2..." << endl;
    g.RemoveEdge(1, 2);
    g.PrintGraph();

    return 0;
}