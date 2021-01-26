#include<bits/stdc++.h>

using namespace std;

// Exponential
int ways(int coins[], int n, int value) {
    if (n == 0) {
        if (value == 0)
            return 1;
        return 0;
    }
    int result = 0;
    if (coins[n - 1] > value)
        result += ways(coins, n - 1, value);
    else    
        result += ways(coins, n - 1, value) + ways(coins, n, value - coins[n - 1]);
    return result;
}

// O(n^2)
int memo[100][100];
int waysTD(int coins[], int n, int value) {
    if (n == 0) {
        if (value == 0)
            return 1;
        else 
            return 0;
    }
    int &result = memo[n][value];
    if (result != -1)
        return result;
    if (coins[n - 1] > value) 
        result = waysTD(coins, n - 1, value);
    else 
        result = waysTD(coins, n - 1, value) + waysTD(coins, n, value - coins[n - 1]);
    return result;
}

// O(n^2)
int waysBU(int coins[], int n, int value) {
    long long int dp[1000][1000];
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= value; j++) {
            if (coins[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else 
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
        } 
    }
    return dp[n][value];
}

// since we have infinite supply of items the value of n is constant so we 
// can solve this problem using one dimensional array
int wayss(int coins[], int n, int value) {
    int dp[1000] = {0};
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= value; j++) {
            if (coins[i] <= j)
                dp[j] += dp[j - coins[i]];
        }
    }
    // for (int i = 0; i <= value; i++)
    //     cout << dp[i] << " ";
    // cout << "\n";
    return dp[value];
}

int main() {
    memset(memo, -1, sizeof(memo));
    int n, value;  cin >> n >> value;
    int coins[n];
    for (int i = 0; i < n; i++) 
        cin >> coins[i];
    cout << ways(coins, n, value) << "\n";
    cout << waysTD(coins, n, value) << "\n";
    cout << waysBU(coins, n, value) << "\n";
    cout << wayss(coins, n, value) << "\n";
    return 0;
}
