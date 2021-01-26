#include<bits/stdc++.h>

using namespace std;

// recursive => Time Complexity: Exponential
int LIS(int arr[], int n, int& max_result) {
    // the subsequence of length 1 is increasing subsequence in itself
    if(n == 1)  return 1;   
    int result = 1;
    for(int i = 1; i < n; i++) {
        int temp = LIS(arr, i, max_result) + 1;
        if(arr[i-1] < arr[n-1])
            result = max(result, temp);
    }
    max_result = max(max_result, result);
    return result;
}

// Space Complexity: O(n)
// recursive with Memoization => Time Complexity: O(n^2)
int memo[100];
int LISTD(int arr[], int n, int& max_result) {
    if(n == 1)  return 1;
    if(memo[n] != -1)   return memo[n];
    int result = 1;
    for(int i = 1; i < n; i++) {
        int temp = LISTD(arr, i, max_result) + 1;
        if(arr[i-1] < arr[n-1]) 
            result = max(result, temp);
    }
    max_result = max(max_result, result);
    return memo[n] = result;
}

// Bottom - Up => Time Complexity: O(n^2)
int LISBU(int arr[], int n) {
    int dp[100] = {1}, result = 1;
    for(int i = 1; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        result = max(result, dp[i]);
    }
    return result;
}

// LIS with restoring the subsequence
int LISBURS(int arr[], int n, vector<int>& res) {
    int dp[100] = {1}, result = 1, itr = 0;
    vector<int> prev(n, -1);
    for(int i = 1; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if(dp[i] >= result)  {
            result = dp[i];
            itr = i;
        }
    }
    while(itr > -1) {
        res.push_back(arr[itr]);
        itr = prev[itr];
    }
    reverse(res.begin(), res.end());
    return result;
}

// optimized => Time Complexity: O(nlogn)
int LISOP(int arr[], int n) {
    // int result = 1;
    // vector<int> vec(n+1, INT_MAX);
    // vec[0] = INT_MIN;
    // for(int i = 0; i < n; i++) {
    //     int j = upper_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
    //     if(vec[j-1] < arr[i] && arr[i] < vec[j])
    //         vec[j] = arr[i];
    // }
    // for(int i = 0; i <= n; i++) {
    //     if(vec[i] < INT_MAX)
    //         result = i;
    // }
    // return result;
    vector<int> vec;    vec.push_back(arr[0]);
    for(int i = 1; i < n; i++) {
        auto j = lower_bound(vec.begin(), vec.end(), arr[i]);
        if(j == vec.end())
            vec.push_back(arr[i]);
        else 
            *j = arr[i];
    }
    return vec.size();
}
// use lower_bound for strictly increasing subsequence
// use upper_bound for increasing subsequence

int LISOPRS(int arr[], int n, vector<int> &res) {
    int result = 1;
    vector<int> vec, index, prev(n, -1);    vec.push_back(arr[0]);
    index.push_back(0);
    for(int i = 1; i < n; i++) {
        auto j = lower_bound(vec.begin(), vec.end(), arr[i]);
        if(j == vec.end()) {
            vec.push_back(arr[i]);
            prev[i] = index.back();
            index.push_back(i); 
        }
        else {
            *j = arr[i];
            prev[i] = prev[index[j - vec.begin()]];
            index[j - vec.begin()] = i;
        }
    }
    int idx = index.back();
    while(idx != -1) {
        res.push_back(arr[idx]);
        idx = prev[idx];
    }
    reverse(res.begin(), res.end());
    return vec.size();
}

int main() {
    //memset(memo, -1, sizeof(memo));
    int n, arr[100];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // int res1 = 0, res2 = 0;
    // LIS(arr, n, res1);
    // LISTD(arr, n, res2);
    // cout << res1 << "\n" << res2 << "\n";
    // cout << LISBU(arr, n) << "\n";
    // cout << LISOP(arr, n) << "\n";
    vector<int> res1, res2;
    cout << LISBURS(arr, n, res1) << "\n";
    for(int i: res1)
        cout << i << " ";
    cout << "\n";
    cout << LISOPRS(arr, n, res2) << "\n";
    for(int i: res2) 
        cout << i << " ";
    cout << "\n";
    return 0;
}
