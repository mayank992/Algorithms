#include<bits/stdc++.h>

using namespace std;
const int INF = 1e9;
const int N = 1e3 + 1;
vector<pair<int, int>> adj[N];
vector<int> d(N, INF), p(N, -1);

void dijkstra(int src) {
    set<pair<int, int>> s;
    s.insert({0, src});    d[src] = 0;
    while (!s.empty()) {
        int v = (s.begin()) -> second;
        s.erase(s.begin());
        for (pair<int, int> u: adj[v]) {
            int nbr = u.first, wt = u.second;
            if (d[v] + wt < d[nbr]) {
                if (s.find({d[nbr], nbr}) != s.end())
                    s.erase({d[nbr], nbr});
                d[nbr] = d[v] + wt;
                p[nbr] = v;
                s.insert({d[nbr], nbr});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back(make_pair(v, wt));
    }
    dijkstra(0);
    for (int i = 0; i < n; i++)
        cout << d[i] << " ";
    cout << "\n";
    for (int i = n - 1; i > 0; i--) {
        cout << i << " -> ";
        for (int v = i; v != -1; v = p[v]) 
            cout << v << " ";
        cout << "\n";
    }
    return 0;
}

// sets perform both operations of finding min and relaxation in O(log n)
// Time Complexity: O(nlogn + mlogn) => O(m logn)
// using fibonacci heaps this complexity can be reduced to O(nlogn + m)
// fibonacci heaps can do second operation in O(1).