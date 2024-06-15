/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <unordered_map>
#include "solution.h"

class Solution {
    int result; // This variable will store the final result.
public:
    // Helper function to check if a number is a power of two.
    bool isPowerOfTwo(int n){
        return n == 0 ? true : !(n&(n-1));
    }

    // DFS function to traverse the binary tree and count pseudo-palindromic paths.
    void dfs(TreeNode* root, int value){
        if(root == 0) return;

        // XOR the current value with 1 shifted to the left by the root's value.
        value ^= 1 << root->val;

        // Check if the current node is a leaf (no left and right children).
        if(root->left == root->right){
            // If the XOR value has at most one '1' bit, it is a pseudo-palindromic path.
            result += static_cast<int>(isPowerOfTwo(value));
        }
        else {
            // Recursively call DFS for the left and right children.
            dfs(root->left, value);
            dfs(root->right, value);
        }
    }

    // Main function to calculate pseudo-palindromic paths in the binary tree.
    int pseudoPalindromicPaths(TreeNode* root) {
        result = 0;
        dfs(root, 0);
        root->left = root->right = 0; // This line seems to be an attempt to free memory, but it may cause issues.
        return result;
    }
};
