#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000
vector<int> graph[MAX];
vector<bool> visited;

void dfs(int u){
    cout << u << " ";
    visited[u] = true;
    for(int i:graph[u])//for(i=0;i<graph[u].size();i++){
        if(!visited[i]){
            dfs(i);
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

    cout << "DFS path is: ";
    dfs(source);

    return 0;
}
