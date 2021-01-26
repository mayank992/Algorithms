#include<bits/stdc++.h>

using namespace std;

int getMaxProfit(int prices[], int i, int j, int year) {
    if (i > j)
        return 0;
    // sell bottle from front
    int choice1 = (prices[i] * year) + getMaxProfit(prices, i + 1, j, year + 1);
    // sell bottle from last
    int choice2 = (prices[j] * year) + getMaxProfit(prices, i, j - 1, year + 1);
    return max(choice1, choice2);
}

int memo[100][100];
int getMaxProfitTD(int prices[], int i, int j, int year) {
    if (i > j)  
        return 0;
    if (memo[i][j] != -1)
        return memo[i][j];
    int choice1 = (prices[i] * year) + getMaxProfitTD(prices, i + 1, j, year + 1);
    int choice2 = (prices[j] * year) + getMaxProfitTD(prices, i, j - 1, year + 1);
    return memo[i][j] = max(choice1, choice2);
}

// int getMaxProfitBU(int prices[], int n) {
//     int dp[100][100], year = n;
//     memset(dp, 0, sizeof(dp));
//     for (int i = 0; i < n; i++) {
//         dp[i][i] = prices[i] * year;
//     }
//     year--;
//     for (int window = 2; window <= n; window++) {
//         int start = 0, end = n - window;
//         while (start <= end) {
//             int i = start, j = start + window - 1;
//             dp[i][j] = max((prices[i] * year) + dp[i + 1][j], (prices[j] * year) + dp[i][j - 1]);
//             start++;
//         }
//         year--;
//     }
//     return dp[0][n - 1];
// }

int getMaxProfitBU(int prices[], int n) {
    int dp[100][100], year = n;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        dp[i][i] = prices[i] * year;
    }
    year--;
    for (int window = 2; window <= n; window++) {
        for (int i = 0, j = window - 1; j < n; i++, j++) {
            dp[i][j] = max((prices[i] * year) + dp[i + 1][j], (prices[j] * year) + dp[i][j - 1]);
        }
        year--;
    }
    return dp[0][n - 1];
}

int main() {
    memset(memo, -1, sizeof(memo));
    int n = 5, prices[] = {2, 3, 5, 1, 4};
    cout << getMaxProfit(prices, 0, n - 1, 1) << "\n";
    cout << getMaxProfitTD(prices, 0, n - 1, 1) << "\n";
    cout << getMaxProfitBU(prices, n) << "\n";
    return 0;
}