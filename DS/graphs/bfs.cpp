#include <bits/stdc++.h>
using namespace std;

class Complex
{
};
class Graph
{
private:
    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }

    void addedge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if (undir)
        {
            l[j].push_back(i);
        }
    }

    void printAdj()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " -> ";
            for (auto node : l[i])
            {
                cout << node << " ";
            }
            cout << endl;
        }
    }

    void bfs(int s)
    { // bfs with source
        queue<int> q;
        vector<bool> visited(V, false);

        q.push(s);
        visited[s] = true;

        while (!q.empty())
        {
            int f = q.front();
            cout << f << endl;
            q.pop();

            for (auto child : l[f])
            {
                if (!visited[child])
                {
                    q.push(child);
                    visited[child] = true;
                }
            }
        }
    }

    void bfs(int s, vector<bool> &visited)
    {
        queue<int> q;
        q.push(s);
        visited[s] = true;

        while (!q.empty())
        {

            int f = q.front();
            cout << f << endl;
            q.pop();
            for (auto v : l[f])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    void bfsdis()
    {
        vector<bool> visited(V + 1, false);

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                bfs(i, visited);
            }
        }
    }

    void dfsrec(int s, vector<bool> &visited)
    {
        visited[s] = true;
        cout << s << " ";
        for (auto u : l[s])
        {
            if (visited[u] == false)
            {
                dfsrec(u, visited);
            }
        }
    }

    void dfs()
    {
        vector<bool> visited(V + 1, false);
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                dfsrec(i, visited);
            }
        }
        cout << "\n";
    }
};

int32_t main()
{

    Graph g(7);
    g.addedge(0, 1);
    g.addedge(1, 2);
    g.addedge(2, 3);
    g.addedge(3, 5);
    g.addedge(5, 6);
    g.addedge(4, 5);
    g.addedge(0, 4);
    g.addedge(3, 4);
    g.bfs(1);
    g.dfs();
    g.bfsdis();
    return 0;
}