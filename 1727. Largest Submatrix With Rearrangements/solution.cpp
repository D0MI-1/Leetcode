#include <iostream>
#include <vector>

class Solution {
public:
    int largestSubmatrix(std::vector<std::vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<std::vector<int>> heights(rows, std::vector<int>(cols, 0));

        for (int j = 0; j < cols; ++j) {
            for (int i = 0; i < rows; ++i) {
                if (matrix[i][j] == 1) {
                    //take value from above and increment by 1
                    heights[i][j] = (i > 0) ? heights[i - 1][j] + 1 : 1;
                }
            }
        }

        int maxSubmatrixArea = 0;
        for (int i = 0; i < rows; ++i) {
            std::sort(heights[i].begin(), heights[i].end(), std::greater<int>());
            for (int j = 0; j < cols; ++j) {
                maxSubmatrixArea = std::max(maxSubmatrixArea, heights[i][j] * (j + 1));
            }
        }

        return maxSubmatrixArea;
    }
};

/*
#pragma GCC optimize("Ofast","inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
static const auto fast = []() {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0; } ();

        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            sort(matrix[i].begin(), matrix[i].end());
            for (int j = 0; j < n; j++) {
                res = max(res, matrix[i][j] * (n - j));
            }
        }
        return res;
    }
*/