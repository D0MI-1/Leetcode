#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();

        // If the matrix has only one row, return the minimum element in that row
        if (n == 1) {
            return *std::min_element(matrix[0].begin(), matrix[0].end());
        }

        // Iterate through the matrix starting from the second row
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Calculate the minimum falling path sum at position (i, j)
                matrix[i][j] += std::min({
                    (j > 0) ? matrix[i - 1][j - 1] : INT_MAX,
                    matrix[i - 1][j],
                    (j < n - 1) ? matrix[i - 1][j + 1] : INT_MAX
                });
            }
        }

        // Find the minimum falling path sum in the last row
        return *std::min_element(matrix[n - 1].begin(), matrix[n - 1].end());
    }
};
