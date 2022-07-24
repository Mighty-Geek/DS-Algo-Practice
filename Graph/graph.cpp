#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int src;
    int nbr;
    int wt;

    Edge(int src, int nbr, int wt)
    {
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};

class Pair
{
public:
    int v;
    string psf;
    Pair(int vt, string path)
    {
        this->v = vt;
        this->psf = path;
    }
};

struct myComp
{
    bool operator()(pair<int, string> &a, pair<int, string> &b)
    {
        return a.first > b.first;
    }
};

bool hasPath(vector<Edge> graph[], int src, int dest, vector<bool> vis)
{
    if (src == dest)
        return true;
    vis[src] = true;
    for (Edge edge : graph[src])
    {
        if (vis[edge.nbr] == false)
        {
            bool nbrPath = hasPath(graph, edge.nbr, dest, vis);
            if (nbrPath == true)
                return true;
        }
    }
    return false;
}

void printAllPaths(vector<Edge> graph[], int src, int dest, vector<bool> vis, string psf)
{
    if (src == dest)
    {
        cout << psf << endl;
        return;
    }
    vis[src] = true;
    for (Edge edge : graph[src])
    {
        if (vis[edge.nbr] == false)
        {
            printAllPaths(graph, edge.nbr, dest, vis, psf + to_string(edge.nbr));
        }
    }
    vis[src] = false;
}

string sPath;
int sPathWt = INT_MAX;
string lPath;
int lPathWt = INT_MIN;
string cPath;
int cPathWt = INT_MAX;
string fPath;
int fPathWt = INT_MIN;
priority_queue<pair<int, string>, vector<pair<int, string>>, myComp> pq;

void multisolver(vector<Edge> graph[], int src, int dest, vector<bool> vis, int criteria, int k, string psf, int wsf)
{
    if (src == dest)
    {
        if (wsf < sPathWt)
        {
            sPathWt = wsf;
            sPath = psf;
        }
        if (wsf > lPathWt)
        {
            lPathWt = wsf;
            lPath = psf;
        }
        if (wsf > criteria && wsf < cPathWt)
        {
            cPathWt = wsf;
            cPath = psf;
        }
        if (wsf < criteria && wsf > fPathWt)
        {
            fPathWt = wsf;
            fPath = psf;
        }

        pair<int, string> p;
        p.first = wsf;
        p.second = psf;

        pq.push(p);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    vis[src] = true;
    for (Edge e : graph[src])
    {
        if (vis[e.nbr] == false)
        {
            multisolver(graph, e.nbr, dest, vis, criteria, k, psf + to_string(e.nbr), wsf + e.wt);
        }
    }
    vis[src] = false;
}
void drawTree(vector<Edge> graph[], int src, vector<int> &comp, vector<bool> &vis)
{
    vis[src] = true;
    comp.push_back(src);
    for (Edge e : graph[src])
    {
        if (vis[e.nbr] == false)
        {
            drawTree(graph, e.nbr, comp, vis);
        }
    }
}

vector<vector<int>> comps;
void getConnectedComponets(vector<Edge> graph[], vector<bool> &vis, int vertices)
{
    for (int v = 0; v < vertices; v++)
    {
        if (vis[v] == false)
        {
            vector<int> comp;
            drawTree(graph, v, comp, vis);
            comps.push_back(comp);
        }
    }
}
bool isGraphConnected(vector<Edge> graph[], vector<bool> &vis, int v)
{
    getConnectedComponets(graph, vis, v);
    int rows = comps.size();
    if (rows == 1)
        return true;
    return false;
}

void bfs(vector<Edge> graph[], int src, vector<bool> &vis)
{
    queue<Pair *> q;
    q.push(new Pair(src, to_string(src) + ""));

    while (q.size() > 0)
    {
        // r m* w a*
        Pair *rem = q.front();
        q.pop();
        if (vis[rem->v] == true)
        {
            continue;
        }
        vis[rem->v] = true;
        cout << rem->v << " @ " << rem->psf << endl;

        for (Edge e : graph[rem->v])
        {
            if (vis[e.nbr] == false)
            {
                q.push(new Pair(e.nbr, rem->psf + to_string(e.nbr)));
            }
        }
    }
}

int main()
{
    int vertices;
    cin >> vertices;
    vector<Edge> graph[vertices];

    int edges;
    cin >> edges;
    for (int i = 0; i < edges; i++)
    {
        int v1;
        int v2;
        int wt;
        cin >> v1 >> v2 >> wt;
        graph[v1].push_back(Edge(v1, v2, wt));
        graph[v2].push_back(Edge(v2, v1, wt));
    }

    // int src, dest;
    // cin >> src >> dest;
    // int k, criteria;
    // cin >> k >> criteria;

    vector<bool> visited(vertices, false);
    // cout << boolalpha << hasPath(graph, src, dest, visited);

    // printAllPaths(graph, src, dest, visited, to_string(src) + " ");

    // multisolver(graph, src, dest, visited, criteria, k, src + "0", 0);
    // cout << "Smallest path: " << sPath << " @ " << sPathWt << endl;
    // cout << "Largest path: " << lPath << " @ " << lPathWt << endl;
    // cout << "Ceil path: " << cPath << " @ " << cPathWt << endl;
    // cout << "Floor path: " << fPath << " @ " << fPathWt << endl;
    // cout << k << "th largest path: " << pq.top().second << " @ " << pq.top().first << endl;

    // getConnectedComponets(graph, visited, vertices);
    // for (int i = 0; i < comps.size(); i++)
    // {
    //     for (int j = 0; j < comps[i].size(); j++)
    //     {
    //         cout << comps[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // bool isConnected = isGraphConnected(graph, visited, vertices);
    // cout << boolalpha << isConnected << endl;

    bfs(graph, 2, visited);
    return 0;
}