#include<bits/stdc++.h>

using namespace std;

int rodCutting(int cost[], int n) {
    if (n == 0) 
        return 0;
    int totalProfit = 0;
    for (int i = 1; i <= n; i++) {
        totalProfit = max(totalProfit, rodCutting(cost, n - i) + cost[i-1]);
    } 
    return totalProfit;
}

int memo[100];
int rodCuttingTD(int cost[], int n) {
    if (n == 0)
        return 0;
    if (memo[n] != -1)   return memo[n];
    int totalProfit = 0;
    for (int i = 1; i <= n; i++) {
        totalProfit = max(totalProfit, rodCuttingTD(cost, n - i) + cost[i-1]);
    }
    return memo[n] = totalProfit;
}

int rodCuttingBU(int cost[], int n) {
    int dp[100] = {0};
    for (int len = 1; len <= n; len++) {
        for (int cut = 1; cut <= len; cut++) {
            dp[len] = max(dp[len], dp[len - cut] + cost[cut - 1]);
        }
    }
    return dp[n];
}

int main() {
    memset(memo, -1, sizeof(memo));
    int n = 8, cost[] = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << rodCutting(cost, n) << "\n";
    cout << rodCuttingTD(cost, n) << "\n";
    cout << rodCuttingBU(cost, n) << "\n";
    return 0;
}
