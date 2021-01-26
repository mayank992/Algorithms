/*
    We are given a directed, unweighted graph G with n vertices and we are given an integer k. The task is the following: 
    for each pair of vertices (i,j) we have to find the number of paths of length k between these vertices. Paths don't 
    have to be simple, i.e. vertices and edges can be visited any number of times in a single path.
*/

#include<bits/stdc++.h>

using namespace std;
int G[100][100], ans[100][100];

void mul(int a[][100], int b[][100], int n) {
    int res[100][100];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            res[i][j] = 0;
            for (int k = 1; k <= n; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = res[i][j];
}

void NPFixedLength(int n, int k) {
    // Creating identity matrix
    for (int i = 1; i <= n; i++) 
        ans[i][i] = 1;  
    while (k) {
        if (k & 1) 
            mul(ans, G, n);
        mul(G, G, n);
        k >>= 1;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u][v] += 1;
    }
    int k;
    cin >> k;
    NPFixedLength(n, k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << i << " -> " << j << ": " << ans[i][j] << "\n"; 
        }
    }
    return 0;
}

// Time Complexity: O(n3 logk)