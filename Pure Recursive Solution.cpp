class Solution {
public:
    // Recursive function to find the length of the Longest Palindromic Subsequence
    int how(string &s, int i, int j) {
        // Base case: If both pointers are at the same character, it's a palindrome of length 1
        if (i == j)
            return 1;

        // Base case: If left index exceeds right, it's an invalid subsequence
        if (i > j)
            return 0;

        // If characters at both ends match, include both and move inward
        if (s[i] == s[j])
            return 2 + how(s, i + 1, j - 1);

        // If characters don't match, try both options and take the maximum
        return max(how(s, i, j - 1), how(s, i + 1, j));
    }

    // Main function to initiate the recursive computation
    int longestPalindromeSubseq(string s) {
        // Start recursion from the full string
        return how(s, 0, s.length() - 1);
    }
};
