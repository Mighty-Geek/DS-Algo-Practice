#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, size, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }

        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// to represent row, col as nodeNo:
// nodeNo= row*n + col
vector<int> indices = {0, 1, 0, -1, 0};

vector<int> solution(int n, int m, vector<pair<int, int>> &queries)
{
    DisjointSet ds(n * m);
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    vector<int> ans;
    for (auto it : queries)
    {
        int row = it.first;
        int col = it.second;
        if (vis[row][col] == 1)
        {
            ans.push_back(cnt);
            continue;
        }
        vis[row][col] = 1;
        cnt++;
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + indices[i];
            int ncol = col + indices[i + 1];

            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m)
            {
                if (vis[nrow][ncol] == 1)
                {
                    int nodeNo = row * m + col;
                    int adjNodeNo = nrow * m + ncol;
                    if (ds.findUParent(nodeNo) != ds.findUParent(adjNodeNo))
                    {
                        cnt--;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int q;
    cin >> q;
    vector<pair<int, int>> queries;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        queries.push_back({a, b});
    }
    // change in count of components after each query
    vector<int> ans = solution(n, m, queries);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}