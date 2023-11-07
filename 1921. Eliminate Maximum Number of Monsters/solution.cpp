#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int eliminateMaximum(std::vector<int>& dist, std::vector<int>& speed) {
        std::vector<float>howManySteps;
        howManySteps.reserve(dist.size());

        for (size_t i = 0; i < speed.size(); i++)
        {
            howManySteps.push_back(static_cast<float>(dist.at(i)) / speed.at(i));
        }

        std::sort(howManySteps.begin(), howManySteps.end());
        
        int kills = 0;

        for (size_t i = 0; i < dist.size(); i++)
        {
            if(howManySteps.at(i) <= kills){
                return kills;
            }

            kills++;
        }
        
        return howManySteps.size();
    }
};

int main(){
    std::vector<int> dist{1,3,4};
    std::vector<int> speed{1,1,1};
    
    Solution solution;

    std::cout << solution.eliminateMaximum(dist, speed) << std::endl;

    return 0;
}
