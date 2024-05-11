//shortest path
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()

struct Edge {
    int destination;
    int weight;
};

void dijkstra(int source, const vector<vector<Edge>>& graph, vector<int>& distance) {
    int n = graph.size();
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance.assign(n, INF);
    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;
        visited[u] = true;

        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight_uv = edge.weight;

            if (distance[u] != INF && distance[u] + weight_uv < distance[v]) {
                distance[v] = distance[u] + weight_uv;
                pq.push({distance[v], v});
            }
        }
    }
}

int main() {
    int n = 5;
    vector<vector<Edge>> graph(n);

    graph[0].push_back({1, 10});
    graph[0].push_back({2, 5});
    graph[1].push_back({2, 2});
    graph[1].push_back({3, 1});
    graph[2].push_back({1, 3});
    graph[2].push_back({3, 9});
    graph[2].push_back({4, 2});
    graph[3].push_back({4, 4});
    graph[4].push_back({3, 6});

    int source = 0;
    vector<int> distance;

    dijkstra(source, graph, distance);

    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "Vertex " << i << ": " << distance[i] << '\n';
    }

    return 0;
} 
