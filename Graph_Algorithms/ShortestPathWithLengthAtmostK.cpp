/*
    Generalization of the problem for shortest paths with length up to k
*/

#include<bits/stdc++.h>

using namespace std;
const int INF = 1e9;
int G[100][100], ans[100][100];

void _init(int n) {
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j <= 2 * n; j++) {
            G[i][j] = INF;
            ans[i][j] = INF;
        }
    }
    for (int i = 1; i <= 2 * n; i++) {
        ans[i][i] = 0;
    }
}

void mul(int a[][100], int b[][100], int n) {
    int res[100][100];
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j <= 2 * n; j++) {
            res[i][j] = INF;
            for (int k = 1; k <= 2 * n; k++) {
                res[i][j] = min(res[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j <= 2 * n; j++) {
            a[i][j] = res[i][j];
        }
    }
}

void solve(int k, int n) {
    k += 1;
    while (k) {
        if (k & 1)  mul(ans, G, n);
        mul(G, G, n);
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
        G[(2 * u) - 1][(2 * v) - 1] = wt;    
    }
    for (int i = 1; i <= n; i++) {
        G[(2 * i) - 1][2 * i] = 0;  // edge from u to u'
        G[2 * i][2 * i] = 0;    // self loop
    }
    int k;  cin >> k;
    solve(k, n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int &res =ans[(i * 2) - 1][j * 2];
            cout << i << " -> " << j << ": ";
            if (res == INF)
                cout << "INF\n";
            else  
                cout << ans[(i * 2) - 1][j * 2] << "\n";
        }
    }
    return 0;
}