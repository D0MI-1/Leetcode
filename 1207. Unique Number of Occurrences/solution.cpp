#include <unordered_map>
#include <vector>

class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        std::unordered_map<int, int> occurrences;
        std::unordered_map<int, int> unique;

        for (const auto& num : arr){
            occurrences[num]++;
        }

        for(const auto& occurrence : occurrences){
            if(unique[occurrence.second] == 1)
                return false;
            
            unique[occurrence.second]++;
        }

        return true;
    }
};