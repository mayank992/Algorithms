/*
Given an array of size n. count number of subsets with given difference.
Eqn1: sum(s1) + sum(s2) = totalSum(arr)
Eqn2: sum(s1) - sum(s2) = difference
   => 2sum(s1)          = totalSum(arr) + difference
   => sum(s1) = (totalSum(arr) + difference) / 2
      Now just count the number of subsets with sum equals sum(s1)
    return 0 if diff is odd and totalSum is even (and vice-versa)

                                OR

Given an array assign signs to elements of array such that after assigning 
the total sum of arrray equals to the given target(diff).
Soln: Same as above problem
    Just take positive elements in one set and negative in other sets 
    and their diff would be equals to the given target.
*/

#include<bits/stdc++.h>

using namespace std;

int CountSubsets(int arr[], int n, int target) {
    int dp[100][100] = {0};
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (arr[i - 1] > target)
                dp[i][j] = dp[i - 1][j];
            else    
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]);
        }
    }
    return dp[n][target];
}

int main() {
    int n, diff, totalSum = 0;  cin >> n >> diff;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        totalSum += arr[i];
    }
    if (((totalSum & 1) && !(diff & 1)) || (!(totalSum & 1) && (diff & 1)))
        cout << 0 << "\n";
    else {
        int target = (totalSum + diff) / 2;
        cout << CountSubsets(arr, n, target) << "\n";
    }
    return 0;
}