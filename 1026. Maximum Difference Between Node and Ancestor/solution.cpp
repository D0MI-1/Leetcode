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

#include <iostream>
#include <vector>
#include "solution.h"

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return dfs(root, root->val, root->val);
    }

private:
    int dfs(TreeNode* root, int minVal, int maxVal) {
        if (!root) {
            return maxVal - minVal;
        }

        // Update min and max values along the path
        minVal = std::min(minVal, root->val);
        maxVal = std::max(maxVal, root->val);

        // Recursively calculate maxAncestorDiff for left and right subtrees
        int leftDiff = dfs(root->left, minVal, maxVal);
        int rightDiff = dfs(root->right, minVal, maxVal);

        // Return the maximum difference from left and right subtrees
        return std::max(leftDiff, rightDiff);
    }
};
