#include <string>

class Solution {
public:
    int maxScore(std::string s) {
        int maxScore = 0;
        int zeros = 0;
        int ones = 0;

        for (size_t i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                ones++;
            }
        }

        for (size_t i = 0; i < s.length() - 1; ++i) {
            if (s[i] == '1') {
                ones--;
            } else {
                zeros++;
            }

            maxScore = std::max(maxScore, ones + zeros);
        }


        return maxScore;
    }
};