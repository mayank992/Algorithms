#include<bits/stdc++.h>

using namespace std;

// Time Complexity: O(3^(n + m + k))
int KOrderedLCS(string &str1, string &str2, int i, int j, int k) {
    if (i == (int )str1.length() || j == (int )str2.length())
        return 0;
    if (str1[i] == str2[j])
        return 1 + KOrderedLCS(str1, str2, i + 1, j + 1, k);
    else {
        // using k to change 1 character
        int case1 = -1;
        if(k > 0)
            case1 = 1 + KOrderedLCS(str1, str2, i + 1, j + 1, k - 1);
        // not using k
        int case2 = max(KOrderedLCS(str1, str2, i + 1, j, k), KOrderedLCS(str1, str2, i, j + 1, k));
        return max(case1, case2);
    }
}

// Time Complexity: O(n * m * k)
int memo[100][100][100];
int KOrderedLCSTD(string &str1, string &str2, int i, int j, int k) {
    if (i == (int )str1.length() || j == (int )str2.length()) 
        return 0;
    if (memo[i][j][k] != -1) 
        return memo[i][j][k];
    if (str1[i] == str2[j]) 
        return memo[i][j][k] = 1 + KOrderedLCSTD(str1, str2, i + 1, j + 1 , k);
    else {
        int case1 = -1;
        if(k > 0)
            case1 = 1 + KOrderedLCSTD(str1, str2, i + 1, j + 1, k - 1);
        int case2 = max(KOrderedLCSTD(str1, str2, i + 1, j, k), KOrderedLCSTD(str1, str2, i, j + 1, k));
        return memo[i][j][k] = max(case1, case2);
    }
}

// Time Complexity: O(n * m * k)
int KOrderedLCSBU(string &str1, string &str2, int k) {
    int dp[100][100][100];    
    int n1 = str1.length(), n2 = str2.length();
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            for (int l = 0; l <= k; l++) {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j][l] = 1 + dp[i - 1][j - 1][l];
                else {
                    int case1 = -1;
                    if (l > 0)   
                        case1 = 1 + dp[i - 1][j - 1][l - 1];
                    dp[i][j][l] = max(case1, max(dp[i - 1][j][l], dp[i][j - 1][l]));
                }
            }
        }
    }
    return dp[n1][n2][k];
}

int main() {
    memset(memo, -1, sizeof(memo));
    string str1 = "abchgk";
	string str2 = "cgbkh";
    string result;
    int k = 2;
    cout << KOrderedLCS(str1, str2, 0, 0, k) << "\n";
    cout << KOrderedLCSTD(str1, str2, 0, 0, k) << "\n";
    cout << KOrderedLCSBU(str1, str2, k) << "\n";
    return 0;
}