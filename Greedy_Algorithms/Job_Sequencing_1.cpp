// Every jobs takes 1 unit time to complete 
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

int main() {
    int n, max = 0, max_profit = 0;
    cin >> n;
    job *jobs = new job[n];
    for(int i = 0; i < n; i++) {
        cin >> jobs[i].jobID >> jobs[i].deadline >> jobs[i].profit;
        if(jobs[i].deadline > max)
            max = jobs[i].deadline;
    }      
    sort(jobs, jobs + n, cmp);
    char *slots = new char[max]{'\0'};
    for(int i = 0; i < n; i++) {
        for(int j = jobs[i].deadline - 1; j >= 0; j--) {
            if(slots[j] == '\0') {
                slots[j] = jobs[i].jobID;
                max_profit += jobs[i].profit;
                break;
            }
        }
    }
    cout << "Maximum profit sequence of jobs: ";
    for(int i = 0; i < max; i++) {
        if(slots[i] != '\0') {
            cout << slots[i] << " ";
        }
    }
    cout << "\n";
    cout << "Maximum profit: " << max_profit << "\n";
    return 0;
}

// Time Complexity: O(n^2)
// It can be optimized using disjoint sets