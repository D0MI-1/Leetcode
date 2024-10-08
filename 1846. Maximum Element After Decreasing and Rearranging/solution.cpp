#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());

        if (arr[0] != 1) {
            arr[0] = 1;
        }

        for (int i = 1; i < arr.size(); ++i) {
            arr[i] = std::min(arr[i], arr[i - 1] + 1);
        }

        return *std::max_element(arr.begin(), arr.end());
    }
};

/*
   int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int largest = 0;
        for(auto num: arr) {
            largest = min(largest + 1, num);
        }

        return largest;
    }
*/