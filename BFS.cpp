#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
vector<int> graph[MAX];
vector<bool> visited;

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    cout << u << " ";

    while(!q.empty()){
        int v = q.front();
        //cout<<v<<" ";
        q.pop();
        for(int i: graph[v])//for(i=0;i<graph[u].size();i++)
            {
           if(!visited[i]){
            q.push(i);
            visited[i] = true;
            cout << i << " ";
           }
        }
    }

}

int main() {

    cout << "Enter the number of nodes and edges: ";
    int node, edge;
    cin >> node >> edge;

    cout << "Enter the graph: ";
    for(int i=0; i<edge; i++){
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    visited.assign(node,false);

    cout << "Enter the starting node: ";
    int source;
    cin >> source;

    cout << "BFS path is: ";
    bfs(source);

    return 0;
}
