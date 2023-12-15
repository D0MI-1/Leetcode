#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::string destCity(std::vector<std::vector<std::string>>& paths) {
        std::unordered_map<std::string, bool> result;
        std::string endNode;

        for(std::vector<std::string>& path : paths) {

            auto it = result.find(path.at(0));
            if (it != result.end()) {
                it->second = true;
            } else {
                result.insert(std::make_pair(path.at(0), true));
}
            it = result.find(path.at(1));
            if (it == result.end()) {
                result.insert(std::make_pair(path.at(1), false));
            }
        }

        for (const auto& entry : result) {
            if (!entry.second) {
                endNode = entry.first;
                break;
            }
        }

        return endNode;
    }
};