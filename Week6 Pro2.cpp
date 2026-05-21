#include <iostream>
#include <queue>
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

    int color[100];

    // Initially no color
    for (int i = 0; i < V; i++) {
        color[i] = -1;
    }

    queue<int> q;

    bool bipartite = true;

    // Start BFS from vertex 0
    color[0] = 0;
    q.push(0);

    while (!q.empty()) {

        int current = q.front();
        q.pop();

        for (int i = 0; i < V; i++) {

            if (graph[current][i] == 1) {

                // If not colored
                if (color[i] == -1) {

                    color[i] = 1 - color[current];
                    q.push(i);
                }

                // Same color means not bipartite
                else if (color[i] == color[current]) {

                    bipartite = false;
                    break;
                }
            }
        }

        if (!bipartite) {
            break;
        }
    }

    if (bipartite) {
        cout << "Yes Bipartite";
    }
    else {
        cout << "Not Bipartite";
    }

    return 0;
}