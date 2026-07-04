#include<iostream>
#include<queue>
using namespace std;

#define V 6

int arr[V][V] =
{
    {1,1,1,0,0,0},
    {1,0,0,1,1,0},
    {1,0,0,0,0,1},
    {0,1,0,0,0,0},
    {0,1,0,0,0,0},
    {0,0,1,0,0,0}
};

bool visited[V]={false};

void dfs(int start)
{
    visited[start]=true;
    cout<<start<<" ";

    for(int i=0;i<V;i++)
    {
        if(arr[start][i]==1 && !visited[i])
        {
            dfs(i);
        }
    }
}

void bfs(int start)
{
    queue<int> q;

    visited[start]=true;
    q.push(start);

    while(!q.empty())
    {
        int v=q.front();
        q.pop();

        cout<<v<<" ";

        for(int i=0;i<V;i++)
        {
            if(arr[v][i]==1 && !visited[i])
            {
                visited[i]=true;
                q.push(i);
            }
        }
    }
}

int main()
{
    cout<<"BFS : ";
    bfs(0);

    // Reset visited array
    for(int i=0;i<V;i++)
        visited[i]=false;

    cout<<"\nDFS : ";
    dfs(0);

    return 0;
}
