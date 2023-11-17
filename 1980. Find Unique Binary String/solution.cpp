#include <iostream>
#include <vector>
#include <bitset>

class Solution {
public:
    std::string findDifferentBinaryString(const std::vector<std::string>& nums) {
        int n = nums[0].size();

        for (int i = 0; i < (1 << n); ++i) {
            std::string binary_str = std::bitset<32>(i).to_string().substr(32 - n);
            if (std::find(nums.begin(), nums.end(), binary_str) == nums.end()) {
                return binary_str;
            }
        }

        return "";
    }
};

/*
Cantor

class Solution {
public:
    string &findDifferentBinaryString(vector<string>& nums) {
        const unsigned short n = nums.size();
        string &r = nums.front();
        for (unsigned short i = 0; i < n; i++)
            r[i] = nums[i][i] ^ 1;
        return r;
    }
};
*/