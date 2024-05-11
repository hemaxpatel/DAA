//kruskal algo
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int source;
    int destination;
    int weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct Subset {
    int parent;
    int rank;
};

int find(vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(vector<Subset>& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

vector<Edge> kruskalMST(int V, vector<Edge>& edges) {
    vector<Edge> MST;
    sort(edges.begin(), edges.end());

    vector<Subset> subsets(V);
    for (int i = 0; i < V; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int edgeCount = 0;
    for (const Edge& edge : edges) {
        int sourceRoot = find(subsets, edge.source);
        int destRoot = find(subsets, edge.destination);

        if (sourceRoot != destRoot) {
            MST.push_back(edge);
            Union(subsets, sourceRoot, destRoot);
            if (++edgeCount == V - 1)
                break;
        }
    }

    return MST;
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    vector<Edge> MST = kruskalMST(V, edges);
    cout << "Edges in Minimum Cost Spanning Tree:\n";
    for (const Edge& edge : MST) {
        cout << edge.source << " - " << edge.destination << " : " << edge.weight << '\n';
    }
    return 0;
}
