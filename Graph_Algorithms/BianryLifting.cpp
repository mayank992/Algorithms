#include<bits/stdc++.h>

using namespace std;
const int N = 14;
vector<int> adj[N];
vector<int> level(N, 0);
int dp[N][N];

void dfs(int v, int par, int l) {
    dp[0][v] = par;
    level[v] = l;
    for (int u: adj[v]) {
        if (u == par) continue;
        dfs(u, v, l + 1);
    }
}

void precompute(int n) {
    memset(dp, -1, sizeof(dp));
    dfs(1, -1, 0);
    for (int i = 1; i <= log2(n); i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i - 1][j] != -1) {
                dp[i][j] = dp[i - 1][dp[i - 1][j]];
            }
        }
    }
}

int lca(int u, int v, int n) {
    if (level[u] > level[v]) swap(u, v);
    int d = level[v] - level[u];
    while (d > 0) {
        int i = log2(d);
        v = dp[i][v];
        d -= (1 << i);
    }
    if (u == v) return u;
    for (int i = log2(n); i >= 0; i--) {
        if (dp[i][v] != -1 && dp[i][u] != dp[i][v]) 
            u = dp[i][u], v = dp[i][v];
    }
    return dp[0][u];
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    precompute(n);
    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        cout << lca(u, v, n) << "\n";
    }
    return 0;
}

/*
13
1 2 1 3 2 4 2 5 3 6 3 7 4 8 5 9 6 10 7 11 8 12 8 13
*/

/*
    Time complexity: O(nlogn): preprocessing
    O(logn): Query
*/