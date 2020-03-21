// Job Sequencing Problem using disjoint sets
#include<bits/stdc++.h>

using namespace std;

class job {
    public:
        int profit, deadline; 
        char jobID;
};

bool cmp(const job& a, const job& b) {
    return a.profit > b.profit;
}

class Disjset {
    int *parent, n;
    public:
        Disjset(int n) {
            parent = new int[n];
            for(int i = 0; i < n; i++) {
                parent[i] = i;
            }
            this -> n = n;
        }
        int _find(int x) {
            if(x == -1) 
                return -1;
            if(parent[x] == x)
                return x;
            parent[x] = _find(parent[x]);
            return parent[x];
        }
        void merge(int x, int y) {
            if(x == -1) {
                parent[y] = -1;
                return ;
            }
            parent[y] = parent[x];
        }
};  

int main() {
    int n, max = 0, max_profit = 0;
    cin >> n;
    job *jobs = new job[n];
    Disjset obj(n);
    for(int i = 0; i < n; i++) {
        cin >> jobs[i].jobID >> jobs[i].deadline >> jobs[i].profit;
        if(jobs[i].deadline > max)
            max = jobs[i].deadline;
    }      
    sort(jobs, jobs + n, cmp);
    for(int i = 0; i < n; i++) {
        int available_slot = obj._find(jobs[i].deadline-1);
        if(available_slot > -1) {
            obj.merge(available_slot-1, available_slot);
            cout << jobs[i].jobID << " ";
        }
    }
    cout << "\n";
    return 0;
}

//Time Complexity: O(nlogn)