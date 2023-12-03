#include<vector>
#include<cmath>

class Solution {
public:
    int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points) {
        int time = 0;
        for(int i = 0; i < points.size() - 1; ++i) {
            int dx = abs(points[i][0] - points[i+1][0]);
            int dy = abs(points[i][1] - points[i+1][1]);
            time += std::max(dx, dy);
        }
        return time;
    }
};