#include<bits/stdc++.h>

using namespace std;
const int N = 1e3 + 1;
vector<pair<pair<int, int>, int>> edge;
vector<int> d(N, INT_MAX), p(N, -1);
int n, m;

void bellmanFord(int src) {
    d[src] = {0};
    for (int i = 1; i < n; i++) {
        bool any = false;
        for (int j = 0; j < m; j++) {
            int u = edge[j].first.first;
            int v = edge[j].first.second;
            int wt = edge[j].second;
            if (d[u] != INT_MAX && d[u] + wt < d[v]) {
                d[v] = max((long long int )INT_MIN, (long long int)d[u] + wt); // for extra measures in case of negative cycles
                p[v] = u;
                any = true;
            }
        }
        if (!any)   return ;
    }
    for (int i = 0; i < m; i++) {
        int u = edge[i].first.first;
            int v = edge[i].first.second;
            int wt = edge[i].second;
            if (d[u] != INT_MAX && d[u] + wt < d[v]) {
                cout << "Negative Cycle from: " << u << " to " << v << "\n";
                return ;
            }
    }
}

void printPath(int vertex) {
    for (int v = vertex; v != -1; v = p[v]) 
        cout << v << " ";
    cout << "\n";
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, wt;   cin >> u >> v >> wt;
        edge.push_back({{u, v}, wt});
    }
    bellmanFord(1);
    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";
    cout << "\n";
    printPath(5);
    return 0;
}

// Time Complexity: O(n * m)

/*
6 9
1 2 2
1 3 4
2 4 3
2 5 2
3 5 -7
6 4 2
5 6 1
3 2 1
4 5 -13
*/