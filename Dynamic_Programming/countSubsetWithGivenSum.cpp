#include<bits/stdc++.h>

using namespace std;

int countSubset(int arr[], int n, int sum) {
    if (n == 0) {
        if (sum == 0)
            return 1;
        else 
            return 0;
    }
    if (arr[n - 1] > sum)
        return countSubset(arr, n - 1, sum);
    else 
        return countSubset(arr, n - 1, sum) + countSubset(arr, n - 1, sum - arr[n - 1]);
}

int memo[100][100];
int countSubsetTD(int arr[], int n, int sum) {
    if (n == 0) {
        if (sum == 0)
            return 1;
        else 
            return 0;
    }
    if (memo[n][sum] != -1)
        return memo[n][sum];
    if (arr[n - 1] > sum)
        return memo[n][sum] = countSubsetTD(arr, n - 1, sum);
    else 
        return memo[n][sum] = countSubsetTD(arr, n - 1, sum) + countSubsetTD(arr, n - 1, sum - arr[n - 1]);
}

int countSubsetBU(int arr[], int n, int sum) {
    int dp[100][100];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] > j) 
                dp[i][j] = dp[i - 1][j];
            else 
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
        }
    }
    return dp[n][sum];
}

int main() {
    memset(memo, -1, sizeof(memo));
    int n, sum;
    cin >> n >> sum;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << countSubset(arr, n, sum) << "\n";
    cout << countSubsetTD(arr, n, sum) << "\n";
    cout << countSubsetBU(arr, n, sum) << "\n";
    return 0;
}