/*
 Given a tree T of N nodes, where each node i has C i coins attached with it. You have to choose a subset 
 of nodes such that no two adjacent nodes (i.e. nodes connected directly by an edge) are chosen and sum 
 of coins attached with nodes in chosen subset is maximum.
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 10;
vector<int> adj[N];
int dp[N][2], C[N];

void dfs(int v, int parent) {
    long long sum1 = 0, sum2 = 0;
    // 0 -> including the current coin
    // 1 -> not including the current coin
    for (int u: adj[v]) {
        if (u == parent) continue;
        dfs(u, v);
        sum1 += dp[u][1];
        sum2 += max(dp[u][0], dp[u][1]);
    }
    // including current coin
    dp[v][0] = C[v] + sum1;
    // not including the current coin
    dp[v][1] = sum2;
}

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> C[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    long long ans = max(dp[1][0], dp[1][1]);
    cout << ans << "\n";
    return 0;
}

// Time Complexity: O(n)