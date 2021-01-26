/*
    We are given a directed weighted graph G with n vertices and an integer k. For each pair of vertices (i,j) 
    we have to find the length of the shortest path between i and j that consists of exactly k edges.
*/
#include<bits/stdc++.h>

using namespace std;
int G[10][10], ans[10][10];

void _init(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            G[i][j] = 1e9;
            ans[i][j] = 1e9;
        }
    }
    for (int i = 1; i <= n; i++) {
        ans[i][i] = 0;
    }
}

void perform(int a[][10], int b[][10], int n) {
    int res[10][10] = {0};
    for (int i =1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            res[i][j] = 1e9;
            for (int k = 1; k <= n; k++) {
                res[i][j] = min(res[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = res[i][j];
        }
    }
}

void SPFixedLength(int k, int n) {
    while (k) {
        if (k & 1)  
            perform(ans, G, n);
        perform(G, G, n);
        k >>= 1;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    _init(n);
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        G[u][v] = wt;
    }
    int k;
    cin >> k;
    SPFixedLength(k, n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << i << " -> " << j << ": ";
            if (ans[i][j] == 1e9)
                cout << "INF";
            else 
                cout << ans[i][j];
            cout << "\n";
        }
    }
    return 0;
}

// Time Complexity: O(n3 logk)