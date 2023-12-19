#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>>& img) {
        int rows = img.size();
        int cols = img[0].size();
        std::vector<std::vector<int>> result(rows, std::vector<int>(cols, 0));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int count = 0;
                int sum = 0;

                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        int newX = i + dx;
                        int newY = j + dy;

                        if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                            sum += img[newX][newY];
                            ++count;
                        }
                    }
                }

                result[i][j] = sum / count;
            }
        }

        return result;
    }
};