#include<bits/stdc++.h>

using namespace std;

class SparseTable {
    private: 
        int MAXN, K;
        vector<int> log;
        vector<vector<int>> st, idx;

    public: 
        SparseTable(int n) {
            MAXN = n;
            K = log2(n);
            st = idx = vector<vector<int>>(K + 1, vector<int> (MAXN));
        }

        // Preprossing Time Complexity: O(MAXN log2(MAXN))
        void precompute(vector<int> &d) {
            for (int i = 0; i < MAXN; i++) {
                idx[0][i] = i;
                st[0][i] = d[i];
            }
            for (int j = 1; j <= K; j++) {
                for (int i = 0; i + (1 << j) <= MAXN; i++) {
                    // using min function
                    int r = i + (1 << (j - 1));
                    if (st[j - 1][i] < st[j - 1][r]) {
                        idx[j][i] = idx[j - 1][i];
                        st[j][i] = st[j - 1][i];
                    }
                    else {
                        idx[j][i] = idx[j - 1][r];
                        st[j][i] = st[j - 1][r];
                    }
                }
            }
        }
        
        // precompute log2 for faster range min/max queries
        void preComputelog() {
            log = vector<int> (MAXN + 1);
            log[1] = 0;
            for (int i = 2; i <= MAXN; i++) {
                log[i] = log[i / 2] + 1;
            }
        }

        // Range Min/Max Query => Time Complexity: O(1)
        int RMQ(int L, int R) {
            int j = log[R - L + 1], i = R - (1 << j) + 1;
            if (st[j][L] < st[j][i])
                return idx[j][L];
            return idx[j][i];
        }
};

vector<int> adj[13];
vector<int> depth, eulerTour, first(13, 0);

void dfs(int v, int parent, int d = 0) {
    first[v] = eulerTour.size();
    eulerTour.push_back(v);
    depth.push_back(d);
    for (int u: adj[v]) {
        if (u == parent) continue;
        dfs(u, v, d + 1);
        depth.push_back(d);
        eulerTour.push_back(v);
    }
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
    }
    dfs(1, 0);
    SparseTable st(eulerTour.size());
    st.precompute(depth);
    st.preComputelog();
    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        int left = first[u], right = first[v];
        if (left > right) swap(left, right);
        int idx = st.RMQ(left, right);
        cout << eulerTour[idx] << "\n";
    }
    return 0;
}
