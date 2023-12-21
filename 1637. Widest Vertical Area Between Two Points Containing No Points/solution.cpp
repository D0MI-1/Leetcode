#include <vector>

class Solution {
public:
    int maxWidthOfVerticalArea(std::vector<std::vector<int>>& points) {
        std::sort(points.begin(), points.end());

        int solution;

        for (int i = 1; i < points.size(); i++) {
            solution = std::max(solution, points[i][0] - points[i - 1][0]);
        }

        return solution;
    }
};