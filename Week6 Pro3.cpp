#include <iostream>
using namespace std;

// DFS function for cycle detection
bool dfs(int graph[][100], int visited[],
         int recStack[], int current, int V) {

    visited[current] = 1;
    recStack[current] = 1;

    for (int i = 0; i < V; i++) {

        if (graph[current][i] == 1) {

            // If not visited
            if (!visited[i]) {

                if (dfs(graph, visited, recStack, i, V)) {
                    return true;
                }
            }

            // If vertex already in recursion stack
            else if (recStack[i]) {
                return true;
            }
        }
    }

    recStack[current] = 0;

    return false;
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

    int visited[100] = {0};
    int recStack[100] = {0};

    bool cycle = false;

    // Check all vertices
    for (int i = 0; i < V; i++) {

        if (!visited[i]) {

            if (dfs(graph, visited, recStack, i, V)) {
                cycle = true;
                break;
            }
        }
    }

    if (cycle) {
        cout << "Yes Cycle Exists";
    }
    else {
        cout << "No Cycle Exists";
    }

    return 0;
}