#include<bits/stdc++.h>

using namespace std;

int memo[100][100];
bool subsetSum(int arr[], int n, int target) {
    if (n == 0) {
        if (target == 0)
            return 1;
        return 0;
    }
    if (memo[n][target] != -1)
        return memo[n][target];
    if (arr[n - 1] > target)
        return memo[n][target] = subsetSum(arr, n - 1, target);
    else 
        return memo[n][target] = (subsetSum(arr, n - 1, target) || subsetSum(arr, n - 1, target - arr[n - 1]));
}

bool subsetSumBU(int arr[], int n, int target) {
    bool dp[n + 1][target + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (arr[i - 1] > j) 
                dp[i][j] = dp[i - 1][j];
            else 
                dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - arr[i - 1]]);
        }
    } 
    return dp[n][target];
}

int main() {
    memset(memo, -1, sizeof(memo));
    int n, totalSum = 0;
    cin >> n;    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        totalSum += arr[i];
    }
    if(totalSum & 1)
        cout << false << "\n";
    else {
        int target = totalSum / 2;
        cout << boolalpha << subsetSum(arr, n, target) << "\n";
        cout << boolalpha << subsetSumBU(arr, n, target) << "\n";
    }
    return 0;
}