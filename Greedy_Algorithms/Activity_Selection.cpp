#include<bits/stdc++.h>

using namespace std;

class Activity {
    public: 
        int start, end, Id;
};  

bool cmp(const Activity& a, const Activity& b) {
    return a.end < b.end;
}

int main() {
    int n, start, end;
    // total number of activities
    cin >> n;
    Activity *data = new Activity[n];
    for(int i = 0; i < n; i++) {
        cin >> start >> end;
        data[i].Id = i+1;
        data[i].start = start;
        data[i].end = end;
    }
    // sort the data in increasing order on the basis of end time
    sort(data, data + n, cmp);
    // result vector to store the Id of each activity which is selected
    vector<int> result = {data[0].Id};
    int j = 0;
    for(int i = 1; i < n; i++) {
        if(data[i].start >= data[j].end) {
            result.push_back(data[i].Id);
            j++;
        }
    }
    cout << "Selected activities are: ";
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << "\n";
    return 0;
}
