#include <iostream>
using namespace std;

bool found = false;

// DFS Function
void dfs(int graph[][100], int visited[],
         int current, int destination, int V) {

    visited[current] = 1;

    // Destination found
    if (current == destination) {
        found = true;
        return;
    }

    // Visit adjacent vertices
    for (int i = 0; i < V; i++) {

        if (graph[current][i] == 1 && visited[i] == 0) {
            dfs(graph, visited, i, destination, V);
        }
    }
}

int main() {

    int V;
    cin >> V;

    int graph[100][100];

    // Input adjacency matrix
    for (int i = 0; i < V; i++) {

        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int source, destination;
    cin >> source >> destination;

    int visited[100] = {0};

    dfs(graph, visited, source, destination, V);

    if (found) {
        cout << "Yes Path Exists";
    }
    else {
        cout << "No Such Path Exists";
    }

    return 0;
}