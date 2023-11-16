#include <vector>
#include <string>

class Solution {
public:
    int countPalindromicSubsequence(std::string s) {
        // Array of characters from 'a' to 'z'
        char c[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        
        int a = 0, t = 0;

        // Iterate through each character in 'c' array
        for (char x : c) {
            int l, r;

            // Find the leftmost occurrence of the current character 'x' in the string 's'
            for (l = 0; l < s.length() && s[l] != x; l++);
            
            // If the character is not present in the string, continue to the next character
            if (l == s.length()) continue;

            // Find the rightmost occurrence of the current character 'x' in the string 's'
            for (r = s.length() - 1; r >= 0 && s[r] != x; r--);
            
            // If the left pointer is greater than or equal to the right pointer, continue to the next character
            if (l >= r) continue;

            // Vector to track unique characters between the left and right pointers
            std::vector<bool> v(128, false);
            t = 0;

            // Iterate through the characters between the left and right pointers
            for (int i = l + 1; i < r; i++) {
                // If the character is not seen before, mark it as seen and increment 't'
                if (!v[s[i]]) {
                    v[s[i]] = true;
                    t++;

                    // If 't' reaches 26 (all unique characters between 'a' and 'z'), break the loop
                    if (t == 26) break;
                }
            }

            // Add the value of 't' to the final result 'a'
            a += t;
        }

        // Return the total count of palindromic subsequences
        return a;
    }
};
