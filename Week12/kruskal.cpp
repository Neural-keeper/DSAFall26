#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
    
    // Comparator to sort edges by weight
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Disjoint Set Union (DSU) to detect cycles easily
struct DSU {
    vector<int> parent;
    
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    // Find the root of a node (with path compression)
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    // Union two sets
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

void kruskalsMST(int V, vector<Edge>& edges) {
    // Step 1: Sort all edges by weight
    sort(edges.begin(), edges.end());

    DSU dsu(V);
    int total_weight = 0;

    cout << "Edges in Kruskal's MST:\n";
    for (const auto& edge : edges) {
        // Check if adding this edge creates a cycle
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unite(edge.u, edge.v);
            cout << edge.u << " -- " << edge.v << " == " << edge.weight << "\n";
            total_weight += edge.weight;
        }
    }
    cout << "Total Weight of MST: " << total_weight << "\n";
}

/*
0 - 10 - 1
| \      |
6   5   15
|     \  |
2 - 4 - 3
*/

int main() {
    int V = 4; // Number of vertices
    
    // List of edges: {source, destination, weight}
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalsMST(V, edges);
    return 0;
}