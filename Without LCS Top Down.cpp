class Solution {
public:
    // 2D DP array to store results of subproblems
    int dp[1001][1001];

    // Recursive function to compute the length of the Longest Palindromic Subsequence (LPS)
    int how(string &s, int i, int j) {
        // Base case: a single character is a palindrome of length 1
        if (i == j)
            return dp[i][j] = 1;

        // Base case: if left index exceeds right, it's an invalid substring
        if (i > j)
            return dp[i][j] = 0;

        // If result is already computed, return it
        if (dp[i][j] != -1)
            return dp[i][j];

        // If characters at both ends match, include both and solve for the inner substring
        if (s[i] == s[j])
            return dp[i][j] = 2 + how(s, i + 1, j - 1);

        // If characters don't match, take the maximum of two options:
        // 1. Exclude left character
        // 2. Exclude right character
        return dp[i][j] = max(how(s, i, j - 1), how(s, i + 1, j));
    }

    // Main function to initialize DP and start the recursive process
    int longestPalindromeSubseq(string s) {
        // Initialize all dp values to -1 (uncomputed)
        memset(dp, -1, sizeof(dp));

        int m = s.length();

        // Start solving from the full string range
        how(s, 0, m - 1);

        // The answer will be stored in dp[0][m-1], i.e., for the entire string
        return dp[0][m - 1];
    }
};
