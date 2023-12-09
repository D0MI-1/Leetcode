#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "solution.h"

class Solution {
public:
    void inorder(TreeNode* root, std::vector<int>& nodes) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> reuslt;
        inorder(root, reuslt);
        return reuslt;
    }
};