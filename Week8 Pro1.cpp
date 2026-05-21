#include <iostream>
#include <climits>
using namespace std;

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

    visited[0] = 1;

    int edges = 0;
    int minWeight = 0;

    // MST contains V-1 edges
    while (edges < V - 1) {

        int minimum = INT_MAX;
        int x = 0;
        int y = 0;

        for (int i = 0; i < V; i++) {

            if (visited[i]) {

                for (int j = 0; j < V; j++) {

                    if (!visited[j] &&
                        graph[i][j] != 0 &&
                        graph[i][j] < minimum) {

                        minimum = graph[i][j];

                        x = i;
                        y = j;
                    }
                }
            }
        }

        visited[y] = 1;

        minWeight += graph[x][y];

        edges++;
    }

    cout << "Minimum Spanning Weight: "
         << minWeight;

    return 0;
}