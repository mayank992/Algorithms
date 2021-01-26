/*
 Given a tree T of N nodes, calculate longest path between any two nodes(also known as diameter of tree).
 The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between 
 two end nodes. 
*/

#include<bits/stdc++.h>

using namespace std;
const int N = 10;
vector<int> adj[N];
int f[N], g[N], diameter;

void dfs(int v, int parent) {
    int maxA = 0, maxB = 0;
    // first maximum & second maximum respectively
    for (int u: adj[v]) {
        if (u == parent) continue;
        dfs(u, v);
        if (f[u] > maxA) {
            maxB = maxA;
            maxA = f[u];
        }
        else if (f[u] > maxB) 
            maxB = f[u];
    }
    f[v] = 1 + maxA;
    g[v] = 1 + maxA + maxB;
    diameter = max(diameter, max(f[v], g[v]));
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << diameter << "\n";
    return 0;
}

// Time complexity: O(n)