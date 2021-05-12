#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    map<int, bool> visited;
    map<int, list<int>> adj_list;

    void addEdge(int v, int w);
    void dfs(int v);
};

void Graph ::addEdge(int v, int w)
{
    adj_list[v].push_back(w);
}

void Graph ::dfs(int v)
{
    visited[v] = true;
    cout << v << " ";

    list<int>::iterator itr;
    for (itr = adj_list[v].begin(); itr != adj_list[v].end(); ++itr)
    {
        if (!visited[*itr])
            dfs(*itr);
    }
}

int main()
{
    Graph g;
    g.addEdge(1, 2);
    g.addEdge(1, 7);
    g.addEdge(1, 8);
    g.addEdge(2, 3);
    g.addEdge(2, 6);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(8, 9);
    g.addEdge(8, 12);
    g.addEdge(9, 10);
    g.addEdge(9, 11);

    cout << "Depth first traversal from node 1 : \t";
    g.dfs(1);

    return 0;
}

/*
// DFS Applications :

1. MST
2. Detection of cycle in a graph
3. Path finding
4. Topological sort
5. Bipartite graph
6. Find strongly connected components of graph
7. Solving puzzles with one soln

*/