#include <string>

class Solution {
public:
    bool halvesAreAlike(std::string s) {
        int length = s.size();
        int half = length / 2;

        std::string firstHalf = s.substr(0, half);
        std::string secondHalf = s.substr(half);

        int vowelFH = 0;
        int vowelSH = 0;

        for(int i = 0; i < half; i++){
            if (isVowel(firstHalf.at(i)))
                vowelFH++;
            if (isVowel(secondHalf.at(i)))
                vowelSH++;

            if (vowelFH > (vowelSH + (half - i)) || vowelSH > (vowelFH + (half - i)))
                return false;
        }

        return vowelFH == vowelSH; 
    }

private: 
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }

};