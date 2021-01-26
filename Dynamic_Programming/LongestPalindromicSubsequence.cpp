#include<bits/stdc++.h>

using namespace std;

int LCS(string &str1, string &str2) {
    int dp[100][100];
    int n1 = str1.length(), n2 = str2.length();
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n1][n2];
}

int LPalindromicSubsequence(string &str1) {
    string str2 = str1;
    reverse(str2.begin(), str2.end());
    return LCS(str1, str2);
}

int main() {
    string str;
    cin >> str;
    cout << LPalindromicSubsequence(str) << "\n";
    return 0;
}