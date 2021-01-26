#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 1;
vector<pair<int, int>> adj[N];
vector<int> dist(N, INT_MAX);

/*
   we can use BFS to solve the SSSP (single-source shortest path)
   problem in O(|E|), if the weights of each edge is either 0 or 1.
   we can also solve this problem with the help of Dijstra's algorithm
   with time complexity: O(E + logV)
*/

void Bfs01(int s) {
    dist.assign(N, INT_MAX);
    deque<int> q;
    q.push_front(s);
    dist[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (pair<int, int> edge: adj[v]) {
            int u = edge.first, w = edge.second;
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                if (w) 
                    q.push_back(u);
                else 
                    q.push_front(u);
            }
        }
    }
}

int main() {
    int n, s, e;
    cin >> n >> s >> e;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    Bfs01(s);
    for (int i = 1; i <= n; i++) 
        cout << dist[i] << " ";
    cout << "\n";
    return 0;
}
