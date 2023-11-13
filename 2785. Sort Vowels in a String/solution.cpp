#include <string>
#include <algorithm>
#include <vector>

class Solution {
public:
    std::string sortVowels(std::string s) {
        std::string vowels;
        std::vector<int> vowelPositions;
        
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isVowel(c)) {
                vowels += c;
                vowelPositions.push_back(i);
            }
        }

        std::sort(vowels.begin(), vowels.end());

        for (int i = 0; i < vowels.size(); ++i) {
            s[vowelPositions[i]] = vowels[i];
        }

        return s;
    }

private:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
};

/*
Faster and less memory usage 
one less string and array instead of vector 
iterates through the string, increments the count of each vowel's ASCII value in the freq array.
For each vowel encountered, it looks for the next non-zero frequency in the freq array and replaces the vowel with the corresponding ASCII character
class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
        ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')return true;

        return false;
    }
    string sortVowels(string s) {
        int freq[128]={0};

        for(int i=0;i<s.size();i++){
            if(isVowel(s[i]))freq[(int)s[i]]++;
        }

        int idx=0;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                while(freq[idx]==0)idx++;
                s[i]=(char)idx;
                freq[idx]--;
            }
        }

        return s;
    }
};
*/