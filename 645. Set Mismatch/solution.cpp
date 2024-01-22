#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findErrorNums(std::vector<int>& nums) {
        std::vector<int> result;
        std::unordered_map<int, int> numMap;

        for (int num : nums) {
            numMap[num]++;
        }

        int missing;

        for (int i = 1; i <= nums.size(); ++i) {
            if (numMap[i] == 2) {
                result.insert(result.begin(), i);  // Duplicate at the beginning
            } else if (numMap[i] == 0) {
                result.push_back(i);  // Missing at the end
            }
        }

        return result;
    }
};