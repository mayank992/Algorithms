/*
Given a string, find length of the longest repeating subseequence such that the two 
subsequence don’t have same string character at same position, i.e., any i’th character 
in the two subsequences shouldn’t have the same index in the original string.
*/

#include<bits/stdc++.h>

using namespace std;

int LongestRepeatedS(string &str) {
    int n = str.length();
    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++)    dp[i][0] = dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (str[i - 1] == str[j - 1] && i != j)
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
    cout << LongestRepeatedS(str) << "\n";
    return 0;   
}