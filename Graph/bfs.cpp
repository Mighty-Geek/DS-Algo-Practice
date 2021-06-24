// BFS

#include <bits/stdc++.h>
using namespace std;

#define MAX 100
vector<int> adj[MAX];
bool visited[MAX];

void init()
{
    for (int i = 0; i < MAX; i++)
    {
        visited[i] = false;
    }
}

void bfs(int src)
{
    init();
    queue<int> q;
    q.push(src);

    int itr, curr_node, next_node;
    cout << "\n---BFS---" << endl;
    while (q.empty() == false)
    {
        curr_node = q.front();
        q.pop();

        if (visited[curr_node] == true)
            continue;

        cout << curr_node << " ";
        visited[curr_node] = true;

        for (itr = 0; itr < adj[curr_node].size(); itr++)
        {
            next_node = adj[curr_node][itr];
            if (visited[next_node] == false)
                q.push(next_node);
        }
    }
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    int src, dest;
    for (int i = 0; i < edges; i++)
    {
        cin >> src >> dest;
        if (src > vertices || dest > vertices)
        {
            cout << "Invalid edge";
            i--;
            continue;
        }
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }
    int initial_node;
    cin >> initial_node;
    bfs(initial_node);
    return 0;
}

// Applications:
// 1. Shortest path
// 2. GPS Navigation system
// 3. Finding path
// 4. Connected components
// 5. Social Networking websites
// 6. Search engine crawlers