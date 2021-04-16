#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; v++)
    {
        cout << v;
        for (auto x : adj[v])
            cout << "->" << x;
        cout << endl;
    }
}

int main()
{
    int v = 5;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 3, 0);

    printGraph(adj, v);
    return 0;
}
