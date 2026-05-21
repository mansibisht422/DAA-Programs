#include <iostream>
#include <climits>
using namespace std;

// Function to print path
void printPath(int parent[], int vertex) {

    if (vertex == -1)
        return;

    printPath(parent, parent[vertex]);

    cout << vertex + 1 << " ";
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

    int source;
    cin >> source;

    source--; // converting to 0-based index

    int dist[100];
    int visited[100] = {0};
    int parent[100];

    // Initialization
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }

    dist[source] = 0;

    // Dijkstra Algorithm
    for (int count = 0; count < V - 1; count++) {

        int minDist = INT_MAX;
        int u = -1;

        // Find minimum distance vertex
        for (int i = 0; i < V; i++) {

            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        // Update adjacent vertices
        for (int v = 0; v < V; v++) {

            if (graph[u][v] != 0 &&
                !visited[v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Printing shortest path and distance
    for (int i = 0; i < V; i++) {

        if (i != source) {

            printPath(parent, i);

            cout << ": " << dist[i] << endl;
        }
    }

    return 0;
}