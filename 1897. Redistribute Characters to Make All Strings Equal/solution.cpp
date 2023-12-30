#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool makeEqual(std::vector<std::string>& words) {
        std::unordered_map<char, int> letterToCount;
        letterToCount.reserve(26);
        int n = words.size();

        for(const auto& word : words){
            for(const auto& c : word){
                letterToCount[c]++;
            }
        }

        for(const auto& [letter, count] : letterToCount){
            if(count % n != 0)
                return false;
        }

        return true;
    }
};

/*class Solution {
public:
    bool makeEqual(vector<string>& words) {

        vector<int> freq(26);
        for(string &word:words)
            for(char &ch:word)
                freq[ch - 'a']++;

        for(int i=0; i<26; i++)
            if(freq[i]%words.size() != 0)
                return false;

        return true;
    }
};*/