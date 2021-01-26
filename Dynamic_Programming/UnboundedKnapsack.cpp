#include<bits/stdc++.h>

using namespace std;

int maxProfit(int wt[], int value[], int n, int capacity) {
    if (n == 0) 
        return 0;
    int result = 0; 
    if (wt[n - 1] > capacity)
        result = max(result, maxProfit(wt, value, n - 1, capacity));
    else 
        result = max(result, max(value[n - 1] + maxProfit(wt, value, n, capacity - wt[n - 1]), maxProfit(wt, value, n - 1, capacity)));
    return result;
}

int memo[1000][1001];
int maxProfitTD(int wt[], int value[], int n, int capacity) {
    if (n == 0) 
        return 0;
    if (memo[n][capacity] != -1)
        return memo[n][capacity];
    int &res = memo[n][capacity] = 0;
    if (wt[n - 1] > capacity)
        res = max(res, maxProfitTD(wt, value, n - 1, capacity));
    else 
        res = max(res, max(value[n - 1] + maxProfitTD(wt, value, n, capacity - wt[n - 1]), maxProfitTD(wt, value, n - 1, capacity)));
    return res;
}

int maxProfitBU(int wt[], int value[], int n, int capacity) {
    int dp[1000][1001] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (wt[i - 1] > j) 
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            else 
                dp[i][j] = max(dp[i][j], max(value[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]));
        }
    }
    return dp[n][capacity];
}

// since we have infinite supply of items the value of n is constant so we 
// can solve theis problem using one dimensional array
int maxProfitBU1D(int wt[], int value[], int n, int capacity) {
    int dp[1000] = {0};
    for (int i = 1; i <= capacity; i ++) {
        for (int j = 0; j <= n; j++) {
            if (wt[j] <= i)
                dp[i] = max(dp[i], value[j] + dp[i - wt[j]]);
        }
    }
    return dp[capacity];
}

int main() {
    memset(memo, -1, sizeof(memo));
    int n, capacity;  cin >> n >> capacity;
    int wt[n], value[n];
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    for (int i = 0; i < n; i++)
        cin >> value[i];
    //cout << maxProfit(wt, value, n, capacity) << "\n";
    cout << maxProfitTD(wt, value, n, capacity) << "\n";
    cout << maxProfitBU(wt, value, n, capacity) << "\n";
    cout << maxProfitBU1D(wt, value, n, capacity) << "\n";
    return 0;
}