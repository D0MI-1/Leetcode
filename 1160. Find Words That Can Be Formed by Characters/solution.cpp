#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int countCharacters(std::vector<std::string>& words, std::string chars) {
        std::unordered_map<char, int> charCount;

        for (char c : chars) {
            charCount[c]++;
        }

        int result = 0;

        for (const std::string& word : words) {
            std::unordered_map<char, int> wordCount;

            for (char c : word) {
                wordCount[c]++;
            }

            bool canFormWord = true;
            for (const auto& entry : wordCount) {
                if (charCount[entry.first] < entry.second) {
                    canFormWord = false;
                    break;
                }
            }

            if (canFormWord) {
                result += word.length();
            }
        }

        return result;
    }
};