#include<bits/stdc++.h>

using namespace std;
const int N = 100;
const int INF = 1e9;
struct Edge {
    int wt = INF, v = -1;
    bool operator<(const Edge &b) const {
        return this -> wt < b.wt;
    }
};
vector<int> minEdge(N, INF);
vector<Edge> adj[N];
//int G[N][N]; 
bool mstSet[N];
int parent[N];

void printMST(int n) {
    for (int v = 1; v < n; v++) {
        cout << parent[v] << " -> " << v << "\n";
    }
}

// Time Complexity: O(n^2) (For Dense Graph)
// int prim1(int n) {
//     int total_wt = 0;
//     minEdge[0] = 0;
//     parent[0] = -1;
//     for (int i = 0; i < n; i++) {
//         int u = -1;
//         // get the min edge, one end of which is connected to the already selected vertex 
//         // and one is connected to the unselected vertex
//         for (int v = 0; v < n; v++) {
//             if (!mstSet[v] && (u == -1 || minEdge[v] < minEdge[u]))
//                 u = v;
//         }
//         if (minEdge[u] == INF) {
//             cout << "No MST!" << "\n";
//             return 0; 
//         }
//         mstSet[u] = true;
//         total_wt += minEdge[u];
//         // update all the adjacent edges of the selected vertex u
//         for (int v = 0; v < n; v++) {
//             if (G[u][v] && !mstSet[v] && G[u][v] < minEdge[v])
//                 parent[v] = u, minEdge[v] = G[u][v];
//         }
//     }
//     return total_wt;
// }

// Time Complexity: O(m logn) (For Sparse Graph) 
int prim2(int n) {
    set<struct Edge> s;
    int total_wt = 0;
    minEdge[0] = 0;
    parent[0] = -1;
    s.insert({0, 0});
    for (int i = 0; i < n; i++) {
        if (s.empty()) {
            cout << "No MST\n";
            return 0;
        }
        int u = (s.begin()) -> v;
        mstSet[u] = 1;
        total_wt += minEdge[u];
        s.erase(s.begin());
        for (Edge e: adj[u]) {
            if (!mstSet[e.v] && e.wt < minEdge[e.v]) {
                parent[e.v] = u;
                s.erase({minEdge[e.v], e.v});
                minEdge[e.v] = e.wt;
                s.insert({minEdge[e.v], e.v});
            }
        }
    }
    cout << total_wt << "\n";
    return 1;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, wt; cin >> u >> v >> wt;
        u -= 1, v -= 1;
        //G[u][v] = G[v][u] = wt;
        adj[u].push_back({wt, v});
        adj[v].push_back({wt, u});
    } 
    if (prim2(n))
        printMST(n);
    return 0;
}

/*
Example:
5 14
1 2 2
1 4 6
2 1 2
2 3 3
2 4 8
2 5 5
3 2 3
3 5 7
4 1 6
4 2 8
4 5 9
5 2 5 
5 3 7
5 4 9
min wt. = 16
0 -> 1
1 -> 2
0 -> 3
1 -> 4
*/