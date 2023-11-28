#include <iostream>
#include <vector>

class Solution {
public:
    const int MOD = 1e9 + 7;

    std::vector<std::vector<int>> moves = {
        {4, 6},   // Node 0
        {6, 8},   // Node 1
        {7, 9},   // Node 2
        {4, 8},   // Node 3
        {0, 3, 9},   // Node 4
        {},       // Node 5 
        {0, 1, 7},   // Node 6
        {2, 6},   // Node 7
        {1, 3},   // Node 8
        {2, 4}    // Node 9
    };

    int knightDialer(int n) {
        std::vector<std::vector<int>> numberCount(n+1, std::vector<int>(10, 0));
        
        for (int i = 0; i <= 9; ++i) 
            numberCount[1][i] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= 9; ++j) {
                for (int k : moves[j]) {
                    numberCount[i][j] = (numberCount[i][j] + numberCount[i-1][k]) % MOD;
                }
            }
        }

        int count = 0;

        for (int i = 0; i <= 9; ++i) 
            count = (count + numberCount[n][i]) % MOD;

        return count;
    }
};

/*
my code bottom-up approach calculating every length from 1 to n and for every ending digit from 0 to 9
n * 10 calculations


top-down approach
recursive function dfs(n, at) distinct numbers of length n ending with digit at
global variable for DP table can be faster than using a local variable due to less overhead with memory allocation 
int dp[5001][10] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
vector<vector<int>> table = {
    {4, 6},
    {8, 6},
    {7, 9},
    {4, 8},
    {3, 9, 0},
    {},
    {0, 1, 7},
    {2, 6},
    {1, 3},
    {2, 4},
};
int MOD = 1e9 + 7;

class Solution {
public:
    int dfs(int n, int at) {
        if (dp[n][at] != 0) {
            return dp[n][at];
        }
        
        int ret = 0;
        for (const auto& from : table[at]) {
            ret = (ret + dfs(n - 1, from)) % MOD;
        }
        return dp[n][at] = ret;
    }
    int knightDialer(int n) {
        int ans = 0;
        for (int i = 0; i < 10; ++i) {
            ans = (ans + dfs(n - 1, i)) % MOD;
        }
        return ans;
    }
};
*/