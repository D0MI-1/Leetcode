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

/*
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int count[26]{};
        int v, res = 0;
        for(char& c : chars) ++count[c - 'a'];
        for(string& word : words) {
            int wCount[26]{};
            bool valid = true;
            for(char& c : word) ++wCount[c - 'a'];
            for(int i = 0; i < 26; i++)
                valid &= count[i] >= wCount[i];
            if(valid) res += word.size();
        }
        return res;
    }
};
*/