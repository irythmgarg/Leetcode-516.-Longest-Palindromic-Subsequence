# Leetcode-516.-Longest-Palindromic-Subsequence

# 💖 Longest Palindromic Subsequence (LPS)

## 🧩 Problem Statement

Given a string `s`, return the **length of the longest palindromic subsequence** in `s`.

A **subsequence** is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
A **palindromic subsequence** reads the same forward and backward.

### ✨ Example:

```
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
```

---

## 🚀 Approaches

### 🟢 1. **Recursive Approach (Without Memoization)**

* **Idea:** Try all possible subsequences using recursion. If the characters match, add 2 and recurse for the inner substring.
* **Time Complexity:** Exponential O(2^n) 😖
* **Space Complexity:** O(n) (stack space)

```cpp
int how(string &s, int i, int j) {
    if (i == j) return 1;
    if (i > j) return 0;
    if (s[i] == s[j]) return 2 + how(s, i + 1, j - 1);
    return max(how(s, i + 1, j), how(s, i, j - 1));
}
```

### 🟡 2. **Top-Down Dynamic Programming (Memoization)**

* **Idea:** Same as recursive, but store results of subproblems in a `dp[i][j]` table to avoid recomputation.
* **Time Complexity:** O(n^2) ✅
* **Space Complexity:** O(n^2) ✅

```cpp
int dp[1001][1001];
int how(string &s, int i, int j) {
    if (i == j) return dp[i][j] = 1;
    if (i > j) return dp[i][j] = 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (s[i] == s[j]) return dp[i][j] = 2 + how(s, i + 1, j - 1);
    return dp[i][j] = max(how(s, i + 1, j), how(s, i, j - 1));
}
```

### 🔵 3. **LCS-Based Approach (Bottom-Up DP)**

* **Idea:** The LPS of a string is equal to the **Longest Common Subsequence (LCS)** of the string and its reverse!
* **Time Complexity:** O(n^2) ✅
* **Space Complexity:** O(n^2) ✅

```cpp
string s2 = s1;
reverse(s2.begin(), s2.end());
vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
```

---

## ⚔️ Comparison of Approaches

| Approach                      | Time Complexity | Space Complexity | Notes                             |
| ----------------------------- | --------------- | ---------------- | --------------------------------- |
| Recursive (no memo)           | O(2^n)          | O(n)             | Slowest, not usable for large `n` |
| Memoized Recursion (Top-Down) | O(n^2)          | O(n^2)           | Efficient, easy to understand     |
| LCS-based Bottom-Up DP        | O(n^2)          | O(n^2)           | Clean iterative solution          |

---

## 👨‍💻 Author Info

**Name:** Ridham Garg
**University:** Thapar Institute of Engineering and Technology, Patiala
**Roll Number:** 102203014
**Passion:** Making dynamic programming look easy! 😄💡

---

If you found this helpful, keep solving and keep smiling! 😊✨

