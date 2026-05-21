#include <iostream>
#include <climits>
using namespace std;

#define INF 1000000

// Function to find shortest path with exactly k edges
int shortestPath(int graph[][100], int source,
                 int destination, int k, int V) {

    // Base Cases
    if (k == 0 && source == destination)
        return 0;

    if (k == 1 && graph[source][destination] != 0)
        return graph[source][destination];

    if (k <= 0)
        return INF;

    int answer = INF;

    // Traverse all adjacent vertices
    for (int i = 0; i < V; i++) {

        if (graph[source][i] != 0) {

            int remainingPath =
                shortestPath(graph, i,
                             destination, k - 1, V);

            if (remainingPath != INF) {

                answer = min(answer,
                             graph[source][i] + remainingPath);
            }
        }
    }

    return answer;
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

    int k;
    cin >> k;

    source--;
    destination--;

    int result =
        shortestPath(graph, source,
                     destination, k, V);

    if (result == INF) {

        cout << "no path of length "
             << k << " is available";
    }
    else {

        cout << "Weight of shortest path from ("
             << source + 1 << ","
             << destination + 1
             << ") with "
             << k
             << " edges : "
             << result;
    }

    return 0;
}