#include <string>
#include <unordered_map>

class Solution {
public:
    int minSteps(std::string s, std::string t) {
        std::unordered_map<char, int> charCount;
        
        for (int i = 0; i < s.size(); i++) {
            charCount[t[i]]++;
            charCount[s[i]]--;
        }

        int ans = 0;

        for (const auto& pair : charCount) {
            ans += std::max(0, pair.second);
        }

        return ans;
    }
};