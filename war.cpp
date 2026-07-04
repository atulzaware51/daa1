#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void warshall(vector<vector<int>> &dist){
    int INF = 1e8;
    int V = dist.size();

    for(int k = 0;k < V;k++){
        for(int i = 0;i < V;i++){
            for(int j = 0;j < V;j++){
                if((dist[i][k] != INF) && (dist[k][j] != INF)){
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main(){

    int INF = 1e8;
    vector<vector<int>> dist = 
    {
        {0,8,INF,1},
        {INF,0,1,INF},
        {4,INF,0,INF},
        {INF,2,9,0}
    };

    warshall(dist);

    for(int i = 0;i < dist.size();i++){
        for(int j = 0;j < dist.size();j++){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}