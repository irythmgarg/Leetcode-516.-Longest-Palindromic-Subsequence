class Solution {
public:
    // Declare a 2D DP array to memoize results for subproblems
    int dp[1001][1001];

    // Recursive helper function to compute Longest Common Subsequence (LCS)
    int hlo(string &s1, string &s2, int i, int j) {
        // Base case: if we reach the end of either string, no more subsequence can be formed
        if (i >= s1.length() || j >= s2.length())
            return 0;

        // If already computed, return the stored result
        if (dp[i][j] != -1)
            return dp[i][j];

        // If current characters match, include it and move to next indices in both strings
        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + hlo(s1, s2, i + 1, j + 1);
        } 
        // If characters don't match, try both possibilities and take the maximum
        else {
            return dp[i][j] = max(hlo(s1, s2, i + 1, j), hlo(s1, s2, i, j + 1));
        }
    }

    // Main function to find the longest palindromic subsequence
    int longestPalindromeSubseq(string s1) {
        // Create a reversed version of the input string
        string s2 = s1;
        reverse(s2.begin(), s2.end());

        // Initialize the DP array with -1 (means unvisited)
        memset(dp, -1, sizeof(dp));

        // Compute the LCS of original and reversed strings
        return hlo(s1, s2, 0, 0);
    }
};
