/*
    Given two strings ‘str1’ and ‘str2’ of size m and n respectively. 
    The task is to remove/delete and insert minimum number of characters 
    from/in str1 so as to transform it into str2. 
*/

#include<bits/stdc++.h>

using namespace std;

// As we can see code is same as LCS
// int getMinOpr(string &str1, string &str2, int i, int j) {
//     if (i == str1.length())
//         return str2.length() - j;
//     if (j == str2.length())
//         return str1.length() - i;
//     if (str1[i] == str2[j])
//         return getMinOpr(str1, str2, i + 1, j + 1);
//     else 
//         return 1 + min(getMinOpr(str1, str2, i, j + 1), getMinOpr(str1, str2, i + 1, j));
// }

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
    return dp[n1][n2];
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    // cout << getMinOpr(str1, str2, 0, 0) << "\n";
    int lcs = LCS(str1, str2);
    int insertion_opr = str2.length() - lcs;
    int deletion_opr = str1.length() - lcs;
    cout << "Insertions: " << insertion_opr << "\n";
    cout << "Deletions: " << deletion_opr << "\n";
    return 0;
}