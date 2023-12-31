#include <string>
#include <unordered_map>

class Solution {
public:
    int maxLengthBetweenEqualCharacters(std::string s) {
        std::unordered_map<char, int> letterToFirstAppearance;
        letterToFirstAppearance.reserve(26);

        int maxLength = -1;

        for (int i = 0; i < s.size(); ++i) {
            char currentChar = s[i];

            if (letterToFirstAppearance.find(currentChar) == letterToFirstAppearance.end()) {
                letterToFirstAppearance[currentChar] = i;
            } else {
                int distance = i - letterToFirstAppearance[currentChar] - 1;
                maxLength = std::max(maxLength, distance);
            }
        }

        return maxLength;
    }
};