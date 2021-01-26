/*
    Given two strings str1 and str2, find the shortest string that has both str1 and str2 as subsequences.
    Examples :

    Input:   str1 = "geek",  str2 = "eke"
    Output: "geeke"

    Input:   str1 = "AGGTAB",  str2 = "GXTXAYB"
    Output:  "AGXGTXAYB"
*/

#include<bits/stdc++.h>

using namespace std;

int LCS(string &str1, string &str2) {
    int n1 = str1.length(), n2 = str2.length();
    int dp[100][100] = {0};
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    // printing SCS
    string result;
    int i = n1, j = n2;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            result.push_back(str1[i - 1]);
            i -= 1;
            j -= 1;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            result.push_back(str1[i - 1]);
            i -= 1;
        }
        else {
            result.push_back(str2[j - 1]);
            j -= 1;
        }
        if (i == 0) {
            while (j > 0) {
                result.push_back(str2[j - 1]);
                j--;
            }
        }
        else if (j == 0) {
            while (i > 0) {
                result.push_back(str1[i - 1]);
                i--;
            }
        }
    }
    reverse(result.begin(), result.end());
    cout << result << "\n";
    return dp[n1][n2];
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    cout << str1.length() + str2.length() - LCS(str1, str2) << "\n";
    return 0;
}