/* MINIMUM COIN CHANGE PROBLEM*/
 
#include<bits/stdc++.h>

using namespace std;

// Recursive solution => Time Complexity: O(n^(money / minCoin))
// maximum number of levels in the recursion tree = (money / minCoin)
int minCoinChange(int coins[], int n, int money) {
    if(money == 0)  return 0;
    int result = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (money - coins[i] >= 0)
            result = min(result, minCoinChange(coins, n, money - coins[i]) + 1);
    }
    return result;
}

// Top-Down with Memoization => Time Complexity: O(n * money)
// Space Complexity: O(money)
int memo[100];
int minCoinChangeTD(int coins[], int n, int money) {
    if(money == 0)  return 0;
    if(memo[money] != -1)   return memo[money];
    int result = INT_MAX;
    for (int i = 0; i < n; i++) {
        if(money - coins[i] >= 0) 
            result = min(result, minCoinChangeTD(coins, n, money - coins[i]) + 1);
    }
    return memo[money] = result;
}

// Bottom-Up => Time Complexity: O(n * money)
// Space Complexity: O(money)
int minCoinChangeBU(int coins[], int n, int money) {
    int dp[100];   
    dp[0] = 0; // initialization
    for (int m = 1; m <= money; m++) {
        dp[m] = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (m - coins[i] >= 0)
                dp[m] = min(dp[m], dp[m - coins[i]] + 1);
        }
    }
    return dp[money];
}

int main() {
    memset(memo, -1, sizeof(memo));   //For Top-Down
    // n is total number of denominations
    int n, coins[100];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    int money;
    cin >> money;
    // Min number coins required to make the change
    cout << minCoinChange(coins, n, money) << "\n";
    cout << minCoinChangeTD(coins, n, money) << "\n";
    cout << minCoinChangeBU(coins, n, money) << "\n"; 
    return 0;
}
/*
    Input: 3        // total number of denominations
           1 6 10   // value of each denomination
           19       // Money
    Output:4        // min number of coins required
           4
           4 
*/
