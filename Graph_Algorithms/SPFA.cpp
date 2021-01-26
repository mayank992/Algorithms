#include<bits/stdc++.h>

using namespace std;
const int N = 1e3 + 1;
vector<pair<int, int>> adj[N];
vector<int> c(N, 0), d(N, INT_MAX);
bool inqueue[N] = {0};
queue<int> q;   int n;

vector<bool> Vis(N, 0);
void dfs(int v) {
    Vis[v] = 1;
    d[v] = INT_MIN;
    for (pair<int, int> u: adj[v]) {
        if (!Vis[u.first]) {
            dfs(u.first);
        }
    }
}

bool spfa(int src) {
    d[src] = 0;
    inqueue[src] = true;
    q.push(src);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inqueue[v] = false;
        for (pair<int, int> u: adj[v]) {
            int vertex = u.first, wt = u.second;
            if (d[v] + wt < d[vertex]) {
                d[vertex] = d[v] + wt;
                if (!inqueue[vertex]) {
                    q.push(vertex);
                    inqueue[vertex] = true;

                    c[vertex] += 1;
                    if (c[vertex] == n) {
                        dfs(vertex);   
                        // set distance of all the nodes which are 
                        // reachable from this particular vertex to -INF
                        return false;   // negative cycle detected
                    }
                }
            }
        }
    }
    return true; 
}

int main() {
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, wt;   cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    if (spfa(1))
        cout << "No any neagtive weight cycle detected.\n";
    else 
        cout << "Negative weight cycle detected.\n";
    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";
    cout << "\n";
    return 0;
}

/*
    1. This is the optimization on the original bellman ford algorithm 
    and runs much better than the bellman ford algo.
    2. On average it can take O(m).
    3. And in worst case it took O(n * m) which is same as Bellman ford algorithm.
*/
