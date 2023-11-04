#include <iostream>
#include <vector>
#include "solution.h"

class Solution {
public:
    int getLastMoment(int n, std::vector<int>& left, std::vector<int>& right) {
        int maxLeft = left.empty() ? 0 : *max_element(left.begin(), left.end()); 
        int minRight = right.empty() ? n : *min_element(right.begin(), right.end());

        return std::max(maxLeft, n - minRight);
    }
};