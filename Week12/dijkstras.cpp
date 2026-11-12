#include <iostream>
#include <vector>
#include <queue>
#include <climit>

using namespace std;

typedef pair<int, int> edge;

void dijkstra(int start, vector<vector<edge>>& graph, int total) {
    vector<int> dist(total, MAX_INT);
    vector<bool> visited(total, false);

    priority_queue<edge, vector<edge>, greater<edge>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto const& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!visited[u] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}