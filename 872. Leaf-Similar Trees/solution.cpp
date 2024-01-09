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
#include <stack>
#include "solution.h"

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> leaves1, leaves2;
        
        dfs(root1, leaves1);
        dfs(root2, leaves2);
        
        return leaves1 == leaves2;
    }

private:
    void dfs(TreeNode* root, std::vector<int>& leaves) {
        if (!root) {
            return;
        }

        if (!root->left && !root->right) {
            leaves.push_back(root->val);
        }

        dfs(root->left, leaves);
        dfs(root->right, leaves);
    }
};