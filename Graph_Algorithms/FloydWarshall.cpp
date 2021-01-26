#include<bits/stdc++.h>

using namespace std;
const int INF = 1e5;
vector<vector<int>> d(10, vector<int>(10, INF));
int p[10][10];

void recur(int i, int j) {
    if (p[i][j] == -1) {
        return ;
    }
    recur(i, p[i][j]);
    cout << p[i][j] << " ";
    recur(p[i][j], j);
}

void solve(int n, int m) {
    memset(p, -1, sizeof(p));
    for (int i = 0; i <= n; i++)
        d[i][i] = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = k;
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m ;
    for (int i = 0; i < m; i++) {
        int u, v, wt;   cin >> u >> v >> wt;
        d[u][v] = wt;
    }
    solve(n, m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }
    cout << 1 << " ";
    recur(1, 5);
    cout << 5 << "\n";
    return 0;
}

// Time Complexity: O(N^3)

/*
4 7
1 2 3
2 1 8
1 4 7
4 1 2
3 1 5
2 3 2
3 4 1
*/