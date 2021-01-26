#include<bits/stdc++.h>

using namespace std;

int LCS(string &str1, string &str2, int i, int j) {
    if(i == str1.length() || j == str2.length())    
        return 0;
    if(str1[i] == str2[j])
        return 1 + LCS(str1, str2, i+1, j+1);
    else 
        return max(LCS(str1, str2, i, j+1), LCS(str1, str2, i+1, j));
}

int memo[100][100];
int LCSTD(string &str1, string &str2, int i, int j) {
    if(i == str1.length() || j == str2.length())
        return 0;
    if(memo[i][j] != -1)    
        return memo[i][j];
    if(str1[i] == str2[j])
        return memo[i][j] =  1 + LCS(str1, str2, i+1, j+1);
    else 
        return memo[i][j] = max(LCS(str1, str2, i, j+1), LCS(str1, str2, i+1, j));
}

int LCSBU(string &str1, string &str2) {
    int n1 = str1.length(), n2 = str2.length();
    int dp[n1 + 1][n2 + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n1; i ++) {
        for (int j = 1; j <= n2; j ++) {
            if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n1][n2];
}

void getLCS(int dp[][100], string &str1, string &str2, int i, int j, string &result) {
    if (i == 0 || j == 0)  
        return ;
    if (str1[i - 1] == str2[j - 1]) {
        result.push_back(str1[i - 1]);
        getLCS(dp, str1, str2, i - 1, j - 1, result);
    }
    else if (dp[i - 1][j] >= dp[i][j - 1])
        getLCS(dp, str1, str2, i - 1, j, result);
    else 
        getLCS(dp, str1, str2, i, j - 1, result);
}

int LCSBUR(string &str1, string &str2, string &result) {
    int n1 = str1.length(), n2 = str2.length();
    int dp[100][100];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else    
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    // Reconstruction Recursive
    // getLCS(dp, str1, str2, n1, n2, result);
    // Reconstruction iterative
    int i = n1, j = n2;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            result.push_back(str1[i - 1]);
            i -= 1, j -= 1;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1])
            i -= 1;
        else 
            j -= 1;
    }
    reverse(result.begin(), result.end());
    return dp[n1][n2];
}

int main() {
    memset(memo, -1, sizeof(memo));
    string str1 = "abchgk";
	string str2 = "cgbkh";
    string result;
    cout << LCS(str1 ,str2, 0, 0) << "\n";
    cout << LCSTD(str1, str2, 0, 0) << "\n";
    cout << LCSBU(str1, str2) << "\n";
    cout << LCSBUR(str1, str2, result) << "\n";
    cout << "Longest Common Subsequence: " << result << "\n";
    return 0;
}