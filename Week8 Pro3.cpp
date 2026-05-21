#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

// Sort in descending order
bool compareEdges(Edge a, Edge b) {
    return a.weight > b.weight;
}

int parent[100];

// Find parent
int findParent(int node) {

    if (parent[node] == node)
        return node;

    return parent[node] =
           findParent(parent[node]);
}

// Union operation
void unionSet(int u, int v) {

    int parentU = findParent(u);
    int parentV = findParent(v);

    parent[parentU] = parentV;
}

int main() {

    int V;
    cin >> V;

    int graph[100][100];

    Edge edges[1000];

    int edgeCount = 0;

    // Input adjacency matrix
    for (int i = 0; i < V; i++) {

        for (int j = 0; j < V; j++) {

            cin >> graph[i][j];

            if (graph[i][j] != 0 && i < j) {

                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].weight = graph[i][j];

                edgeCount++;
            }
        }
    }

    // Sort edges in descending order
    sort(edges, edges + edgeCount, compareEdges);

    // Initialize parent
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int maxWeight = 0;
    int edgesUsed = 0;

    // Maximum Spanning Tree
    for (int i = 0;
         i < edgeCount && edgesUsed < V - 1;
         i++) {

        int u = edges[i].u;
        int v = edges[i].v;

        if (findParent(u) != findParent(v)) {

            unionSet(u, v);

            maxWeight += edges[i].weight;

            edgesUsed++;
        }
    }

    cout << "Maximum Spanning Weight: "
         << maxWeight;

    return 0;
}