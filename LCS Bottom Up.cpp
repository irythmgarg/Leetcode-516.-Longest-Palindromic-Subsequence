class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        // Step 1: Create a reversed version of the original string
        string s2 = s1;
        reverse(s2.begin(), s2.end());

        int m = s1.length();
        int n = s2.length();

        // Step 2: Initialize a DP table of size (m+1) x (n+1) with all values 0
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Step 3: Fill the DP table
        // dp[i][j] will store the length of the longest common subsequence
        // between s1[0..i-1] and s2[0..j-1]
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    // If characters match, increase length by 1 from previous diagonal
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    // If characters don't match, take max of left and top cell
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Step 4: The result is the length of the longest palindromic subsequence
        return dp[m][n];
    }
};
