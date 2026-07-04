#include <iostream>
using namespace std;

#define V 5
#define INF 99999

// Helper function to find the unvisited node with the minimum distance
int minDistance(int dist[], bool visited[]) {
    int min = INF, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Fixed missing parameter type for 'start'
void dijkstra(int graph[V][V], int start) {
    int dist[V];
    bool visited[V];

    // Initialization separated by semicolons, not '&'
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false; // Fixed quote marks around false
    }

    dist[start] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int j = 0; j < V; j++) {
            // Update dist[j] if it's unvisited, has an edge, and path is shorter
            if (!visited[j] && graph[u][j] != 0 && dist[u] != INF && dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    cout << "Vertex \t Distance from Source 0\n";
    for (int i = 0; i < V; i++) {
        // Fixed standard print syntax
        cout << i << " \t " << dist[i] << endl;
    }
}

int main() {
    int graph[V][V] = {
        {0, 10, 3, 0, 0},
        {10, 0, 1, 2, 0},
        {3, 1, 0, 8, 2},
        {0, 2, 8, 0, 7},
        {0, 0, 2, 7, 0}
    };
    
    dijkstra(graph, 0);
    return 0;
}
