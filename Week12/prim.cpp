#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Pair format: {weight, vertex}
typedef pair<int, int> pii;

void primsMST(int V, vector<vector<pii>>& adj) {
    // Min-priority queue to store edges: {weight, vertex}
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<bool> inMST(V, false);
    int total_weight = 0;

    // Start from vertex 0 with weight 0
    pq.push({0, 0});

    cout << "Edges in Prim's MST:\n";
    while (!pq.empty()) {
        int u = pq.top().second; // destination
        int weight = pq.top().first; // weight of edge
        pq.pop();

        // If the vertex is already in the MST, skip it
        if (inMST[u]) continue;

        // Include vertex in MST
        inMST[u] = true;
        total_weight += weight;
        
        if (weight > 0) {
            cout << "Weight: " << weight << " (Node added)\n";
        }

        // Visit all adjacent vertices
        for (auto& neighbor : adj[u]) {
            int v = neighbor.first; // destination
            int wt = neighbor.second; // weight 

            // If 'v' is not in MST, push it to priority queue
            if (!inMST[v]) {
                pq.push({wt, v});
            }
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
    int V = 4;
    vector<vector<pii>> adj(V);

    // Graph representation (Adjacency list): {vertex, weight}
    adj[0].push_back({1, 10});
    adj[1].push_back({0, 10});

    adj[0].push_back({2, 6});
    adj[2].push_back({0, 6});

    adj[0].push_back({3, 5});
    adj[3].push_back({0, 5});

    adj[1].push_back({3, 15});
    adj[3].push_back({1, 15});

    adj[2].push_back({3, 4});
    adj[3].push_back({2, 4});

    primsMST(V, adj);
    return 0;
}