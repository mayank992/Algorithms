#include<bits/stdc++.h>

using namespace std;

int memo[100][100];
int LCSubstring(string &str1, string &str2, int i, int j, int &maxSoFar) {
    if (i == str1.length() || j ==str2.length())
        return 0;
    if (memo[i][j] != -1)   return memo[i][j];
    if (str1[i] == str2[j]) {
        memo[i][j] = 1 + LCSubstring(str1, str2, i + 1, j + 1, maxSoFar);
        if (memo[i][j] > maxSoFar)
            maxSoFar = memo[i][j];
        return memo[i][j];
    }
    LCSubstring(str1, str2, i + 1, j, maxSoFar);  
    LCSubstring(str1, str2, i, j + 1, maxSoFar);    
    return memo[i][j] = 0;
}

int LCSubstringBU(string &str1, string &str2) {
    int n1 = str1.length(), n2 = str2.length();
    int dp[100][100] = {0}, ans = 0;
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else 
                dp[i][j] = 0;
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

int main() {
    memset(memo, -1, sizeof(memo));
    string str1, str2, result;
    int ans = 0;
    cin >> str1 >> str2;
    LCSubstring(str1, str2, 0, 0, ans);
    cout << ans << "\n";
    cout << LCSubstringBU(str1, str2) << "\n";
    return 0;
}