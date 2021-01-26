#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 1;
vector<int> adj[N];
vector<int> pre(N), dist(N, 0);

void bfs(int s) {
    queue<int> q;   bool Vis[N] = {0};
    q.push(s);
    Vis[s] = true;
    pre[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u: adj[v]) {
            if (!Vis[u]) {
                Vis[u] = 1;
                q.push(u);
                dist[u] = dist[v] + 1;
                pre[u] = v;
            }
        }
    }
}

int main() {
    int n, s, e;
    cin >> n >> s >> e;
    for (int i = 0; i < e; i++) {
        int u, v;   cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(s);
    int u = 5; // path from source vertex to the vertex u
    vector<int> path;
    for (int v = u; v != -1; v = pre[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    for (int v: path)
        cout << v << " ";
    cout << "\n";
    return 0;
}

/*
    The algorithm works in O(n+m) time, where n is number of vertices and m is the number of edges.
*/