#include<bits/stdc++.h>

using namespace std;

bool isExist(int arr[], int n, int sum) {
    if (sum == 0)   return 1;
    if (n == 0)     return 0;
    if (sum < arr[n - 1])
        return isExist(arr, n - 1, sum);     
    return isExist(arr, n - 1, sum - arr[n - 1]) || isExist(arr, n - 1, sum);
}

bool memo[100][100];
bool isExistTD(int arr[], int n, int sum) {
    if (sum == 0)    return 1;
    if (n == 0)     return 0;
    if(memo[n][sum] != 0)
        return memo[n][sum];
    if (sum < arr[n - 1])
        return memo[n][sum] = isExist(arr, n - 1, sum);
    return memo[n][sum] = (isExist(arr, n - 1, sum - arr[n - 1]) || isExist(arr, n - 1, sum));
}

bool isExistBU(int arr[], int n, int sum) {
    bool dp[100][100];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < arr[i - 1])
                dp[i][j] = dp[i - 1][j];
            else 
                dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - arr[i - 1]]);
        } 
    }
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= sum; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }
    return dp[n][sum];
}

int main() {
    memset(memo, 0, sizeof(memo));
    //int n = 5, arr[] = {2, 3, 7, 8, 10}, sum = 11;
    int n = 3, arr[] = {1, 2, 7}, sum = 10;
    // cout << isExist(arr, n, sum) << "\n";
    // cout << isExistTD(arr, n, sum) << "\n";
    cout << isExistBU(arr, n, sum) << "\n";
    return 0;
}