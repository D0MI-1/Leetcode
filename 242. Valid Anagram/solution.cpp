#include <string>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::unordered_map<char, int> ss;
        std::unordered_map<char, int> tt;

        for (char ch = 'a'; ch <= 'z'; ch++) {
            ss[ch] = 0;
            tt[ch] = 0;
        
        }

        for(char c : s){
            ss[c]++;
        }

        for(char c : t){
            tt[c]++;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (ss[ch] != tt[ch])
                return false;
        }

        return true;
    }
};