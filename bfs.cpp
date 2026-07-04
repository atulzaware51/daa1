#include <iostream>
#include <queue>
using namespace std;

#define V 6

// Added proper function signature and graph parameter
void BFS(int graph[V][V], int start) {
    bool visited[V] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int a = q.front();
        q.pop();
        cout << a << " "; // Fixed print syntax

        for (int i = 0; i < V; i++) {
            // Check if there is an edge (graph[a][i] == 1) and it's unvisited
            if (!visited[i] && graph[a][i] == 1) {
                visited[i] = true;
                q.push(i); // Added missing semicolon
            }
        }
    }
}

int main() {
    // Added standard curly braces for 2D array
    int graph[V][V] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0}
    };
    
    cout << "BFS Traversal starting from node 0: ";
    BFS(graph, 0);
    cout << endl;
    
    return 0;
}
