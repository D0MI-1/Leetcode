#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches) {
        std::unordered_map<int, int> lossCount;

        for (const auto& match : matches) {
            lossCount[match[0]] += 0;
            lossCount[match[1]]++;
        }

        std::vector<int> zeroLossVec, oneLossVec;

        for (const auto& entry : lossCount) {
            if (entry.second == 0) {
                zeroLossVec.push_back(entry.first);
            } else if (entry.second == 1) {
                oneLossVec.push_back(entry.first);
            }
        }

        std::sort(zeroLossVec.begin(), zeroLossVec.end());
        std::sort(oneLossVec.begin(), oneLossVec.end());

        return {zeroLossVec, oneLossVec};
    }
};
