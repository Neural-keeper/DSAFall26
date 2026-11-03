#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class Vertex {
public:
    int id;
    T data;

    vector<Vertex*> neighbors; // adjacency list representation of the graph
    // neighbors are adjacent vertices connected to this vertex

    void addNeighbor(Vertex* neighbor) {
        neighbors.push_back(neighbor);
    }

    Vertex(int id, T data) : id(id), data(data) {} // the id of the vertex is set during construction
    // so, we can have unique ids for each vertex in the graph, where data can be the same
};  

template <typename T>
class adjacencyListGraph {
private:
    vector<Vertex<T>*> vertices; // list of all vertices in the graph

public:
    ~adjacencyListGraph() {
        for (Vertex<T>* vertex : vertices) {
            delete vertex; // free memory for each vertex
        }
    }

    void addVertex(Vertex<T>* vertex) {
        vertices.push_back(vertex);
    }

    void addEdge(Vertex<T>* v1, Vertex<T>* v2) {
        v1->addNeighbor(v2);
        v2->addNeighbor(v1); // for undirected graph
    }

    void removeVertex(Vertex<T>* vertex) {
        // Remove the vertex from the graph
        int id = vertex->id;
        for (auto it = vertices.begin(); it != vertices.end(); ++it) {
            if ((*it)->id == id) {
                delete *it; // free memory for the vertex
                vertices.erase(it);
                break;
            }
        }
        // Remove the vertex from the neighbors of other vertices
        for (Vertex<T>* v : vertices) {
            for (auto it = v->neighbors.begin(); it != v->neighbors.end(); ++it) {
                if ((*it)->id == id) {
                    v->neighbors.erase(it);
                    break;
                }
            }
        }
    }

    void removeEdge(Vertex<T>* v1, Vertex<T>* v2) {
        // Get the IDs of the vertices
        int id1 = v1->id;
        int id2 = v2->id;
        // Remove the edge between v1 and v2
        for (auto it = v1->neighbors.begin(); it != v1->neighbors.end(); ++it) {
            if ((*it)->id == id2) {
                v1->neighbors.erase(it);
                break;
            }
        }
        for (auto it = v2->neighbors.begin(); it != v2->neighbors.end(); ++it) {
            if ((*it)->id == id1) {
                v2->neighbors.erase(it);
                break;
            }
        }
    }

    void printGraph() {
        for (Vertex<T>* vertex : vertices) {
            cout << "Vertex " << vertex->id << " (" << vertex->data << ") is connected to: ";
            for (Vertex<T>* neighbor : vertex->neighbors) {
                cout << neighbor->id << " (" << neighbor->data << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    adjacencyListGraph<string> graph;

    // Create vertices
    Vertex<string>* v1 = new Vertex<string>(1, "A");
    Vertex<string>* v2 = new Vertex<string>(2, "B");
    Vertex<string>* v3 = new Vertex<string>(3, "C");
    Vertex<string>* v4 = new Vertex<string>(4, "D");

    // Add vertices to the graph
    graph.addVertex(v1);
    graph.addVertex(v2);
    graph.addVertex(v3);
    graph.addVertex(v4);

    // Add edges
    graph.addEdge(v1, v2);
    graph.addEdge(v1, v3);
    graph.addEdge(v2, v4);

    // Print the graph
    graph.printGraph();

    // Remove an edge and print the graph again
    cout << "\nRemoving edge between 1 and 2...\n";
    graph.removeEdge(v1, v2);
    graph.printGraph();

    // Remove a vertex and print the graph again
    cout << "\nRemoving vertex 3...\n";
    graph.removeVertex(v3);
    graph.printGraph();

    return 0;
}