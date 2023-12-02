#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>

class Solution {
public:
    bool arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2) {
        std::string w1;
        std::string w2;

        if(word1.size() > 0){
            for(auto word : word1){
                w1 += word;
            }
        }

        if(word2.size() > 0){
            for(auto word : word2){
                w2 += word;
            }
        }

        return w1.compare(w2);        
    }
};