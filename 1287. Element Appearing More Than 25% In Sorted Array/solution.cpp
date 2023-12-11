#include<vector>
#include<cmath>
#include<unordered_map>

class Solution {
public:
    int findSpecialInteger(std::vector<int>& arr) {
        std::unordered_map<int,int> solution;

        for(int i : arr){
            solution[i]++;
        }

        auto maxIterator = std::max_element(solution.begin(), solution.end(),
                [](const auto& pair1, const auto& pair2) {
            return pair1.second < pair2.second;
            }
        );

        return maxIterator->first;
    }
};