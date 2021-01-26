/*
Given a string str, the task is to find the minimum number of characters 
to be inserted to convert it to palindrome.
*/

#include<bits/stdc++.h>

using namespace std;

int LCS(string &str1) {
    int n =str1.length();
    string str2 = str1;
    reverse(str2.begin(),str2.end());
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
        }
    }
    return dp[n][n];
}

int main() {
    string str;
    cin >> str;
    cout << str.length() - LCS(str) << "\n";
    return 0;
}