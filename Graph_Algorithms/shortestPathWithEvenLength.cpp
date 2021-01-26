#include <bits/stdc++.h>

using namespace std;
vector<pair<int, bool>> adj[100][2];    // 2nd dimension is for the parity of node
// 0 is even parity and 1 is odd
bool Vis[100][2] = {0};
int dist[100][2];

int bfs(int src, int dest) {
    queue<pair<int, bool>> q;
    q.push(make_pair(src, 0));
    Vis[src][0] = 1;
    while (!q.empty()) {
        int v = q.front().first, p = q.front().second;
        q.pop();
        for (pair<int, bool> &u: adj[v][p]) {
            if (!Vis[u.first][u.second]) {
                Vis[u.first][u.second] = 1;
                dist[u.first][u.second] = dist[v][p] + 1;
                q.push(make_pair(u.first, u.second));
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= dest; j++) {
            cout << dist[j][i] << " ";
        } 
        cout << "\n";
    }
    return dist[dest][0];
}

int main() {
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int u, v;   cin >> u >> v;
        adj[u][0].push_back(make_pair(v, 1));
        adj[u][1].push_back(make_pair(v, 0));
        adj[v][0].push_back(make_pair(u, 1));
        adj[v][1].push_back(make_pair(u, 0));
    }
    cout << bfs(1, n) << "\n";
    return 0;
}