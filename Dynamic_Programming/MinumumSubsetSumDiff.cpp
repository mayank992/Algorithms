/*
Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums 
is minimum.
If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of 
abs(sum(Subset1) – sum(Subset2)) should be minimum.
*/

#include<bits/stdc++.h>

using namespace std;

int minSubsetSumDiff(int arr[], int n, int curSum, int totalSum) {
    if (n == 0)
        return abs((totalSum - curSum) - curSum);
    // Not including current element in set1
    int case1 = minSubsetSumDiff(arr, n - 1, curSum, totalSum);
    // Including current element in set1
    int case2 = minSubsetSumDiff(arr, n - 1, curSum + arr[n - 1], totalSum);
    return min(case1, case2);
}

int memo[100][100];
int minSubsetSumDiffTD(int arr[], int n, int curSum, int totalSum) {
    if (n == 0)
        return abs((totalSum - curSum) - curSum);
    if (memo[n][curSum] != -1)
        return memo[n][curSum];
    // Not including current element in set1
    int case1 = minSubsetSumDiff(arr, n - 1, curSum, totalSum);
    // Including current element in set1
    int case2 = minSubsetSumDiff(arr, n - 1, curSum + arr[n - 1], totalSum);
    return memo[n][curSum] = min(case1, case2);
}

int main() {
    memset(memo, -1, sizeof(memo));
    int n, totalSum = 0;  cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        totalSum += arr[i];
    }
    cout << minSubsetSumDiff(arr, n, 0, totalSum) << "\n";
    cout << minSubsetSumDiffTD(arr, n, 0, totalSum) << "\n";
    return 0;
}