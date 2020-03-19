#include<bits/stdc++.h>

using namespace std;

class Item {
    public: 
        int value, weight;
        double fraction;
    
        Item() {
            value = weight = fraction = 0;
        }
};

bool cmp(const Item& a, const Item& b) {
    return a.fraction > b.fraction;
}

int main() {
    int n, w, value, weight;
    // n is total number of items & w is knapsack capacity
    cin >> n >> w;
    // array which stores value, weight, fraction of each item
    Item *data = new Item[n];
    // input
    for(int i = 0; i < n; i++) {
        cin >> value >> weight;
        data[i].value = value;
        data[i].weight = weight;
        data[i].fraction = (double )value / weight;
    }
    // sort the data in non-decreasing order on the basis of the ratioof value/weight
    sort(data, data + n, cmp);
    int cur_weight = 0, final_value = 0;
    for(int i = 0; i < n; i++) {
        if(w - cur_weight >= data[i].weight) {
            cur_weight += data[i].weight;
            final_value += data[i].value;
        }
        else {
            final_value += (w - cur_weight) * data[i].fraction;
            break;
        }
        if(w == cur_weight)
            break;
    }
    cout << "Maximum Value in knapsack: " << final_value << "\n";
    return 0;
}

// Time Complexity : O(nlogn)
// main time taking is sorting