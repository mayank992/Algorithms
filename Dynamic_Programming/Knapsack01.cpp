#include <bits/stdc++.h>

using namespace std;

int getMaxValue(int wt[], int value[], int n, int capacity) {
    if (n == 0 || capacity == 0)
        return 0;
    if (wt[n-1] <= capacity) 
        return max(value[n - 1] + getMaxValue(wt, value, n - 1, capacity - wt[n - 1]), getMaxValue(wt, value, n - 1, capacity));
    else 
        return getMaxValue(wt, value, n - 1, capacity);
}

int memo[100][100];
int getMaxValueTD(int wt[], int value[], int n, int capacity) {
    if (n == 0 || capacity == 0)
        return 0;
    if (memo[n][capacity] != -1)    
        return memo[n][capacity];
    if (wt[n - 1] <= capacity) 
        return memo[n][capacity] = max(value[n - 1] + getMaxValueTD(wt, value, n - 1, capacity - wt[n - 1]), getMaxValueTD(wt, value, n - 1, capacity));
    else 
        return memo[n][capacity] = getMaxValueTD(wt, value, n - 1, capacity);
}

void reConstructRecursive(int dp[][100], int wt[], int n, int capacity, vector<int>& result) {
    if (n == 0) 
        return ;
    if (dp[n][capacity] > dp[n - 1][capacity]) {
        result.push_back(n);
        reConstructRecursive(dp, wt, n - 1, capacity - wt[n - 1], result);
    }
    else 
        reConstructRecursive(dp, wt, n - 1, capacity, result);
}

int getMaxValueBU(int wt[], int value[], int n, int capacity, vector<int>& result) {
    int dp[n + 1][100];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {    // j is current capacity of knapsack
            if (wt[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], value[i - 1] + dp[i - 1][j - wt[i - 1]]);
            else 
                dp[i][j] = dp[i - 1][j];
        }
    }
    // reconstruction recursive
    //reConstructRecursive(dp, wt, n, capacity, result);
    // reconstruction iterative
    int curCapacity = capacity;
    for (int i = n; i > 0; i--) {
        if (dp[i][curCapacity] > dp[i - 1][curCapacity]) {
            result.push_back(i);
            curCapacity -= wt[i - 1];
        }
    }
    reverse(result.begin(), result.end());
    return dp[n][capacity];
}

int main()  {
    memset(memo, -1, sizeof(memo)); vector<int> result;
    int n = 4, wt[] = {1, 3, 4, 5}, value[] = {1, 4, 5, 7}, capacity = 7;
    cout << getMaxValue(wt, value, n, capacity) << "\n";
    cout << getMaxValueTD(wt, value, n, capacity) << "\n";
    cout << getMaxValueBU(wt, value, n, capacity, result) << "\n";
    cout << "Items included: ";
    for (int item: result)
        cout << item << " ";
    cout << "\n";
    return 0;
}
