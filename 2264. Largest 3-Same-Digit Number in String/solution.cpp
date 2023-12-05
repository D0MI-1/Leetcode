#include <iostream>
#include <vector>
#include <string>
#include <regex>

class Solution {
public:
    std::string largestGoodInteger(std::string num) {
        std::regex pattern("(\\d)\\1\\1");
        
        std::sregex_iterator iter(num.begin(), num.end(), pattern);
        std::sregex_iterator end;

        std::vector<int> capturedDigits;

        while (iter != end) {
            std::smatch match = *iter;
            int capturedDigit = std::stoi(match[1].str());
            capturedDigits.push_back(capturedDigit);
            ++iter;
        }

        if (!capturedDigits.empty()) {
            int largestDigit = *std::max_element(capturedDigits.begin(), capturedDigits.end());
            return std::to_string(largestDigit) + std::to_string(largestDigit) + std::to_string(largestDigit);
        }

        return "";
    }
};

/*faster solution maybe regex just bloated
class Solution {
public:
    string largestGoodInteger(string num) {
        vector <int> temp;
        for (int i=0;i<num.size()-2;i++){
            if (num[i]==num[i+1] && num[i]==num[i+2]){
                temp.push_back(stoi(string(1, num[i])));
            }
        }
        sort(temp.begin(),temp.end());
        string ans="";
        if (temp.size()==0){return ans;}
        ans+=to_string(temp[temp.size()-1]);
        ans+=ans+ans;
        return ans;
    }
};
*/