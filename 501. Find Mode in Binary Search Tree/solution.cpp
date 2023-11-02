#include <iostream>
#include <vector>
#include <unordered_map>
#include "solution.h"

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
class Solution {
public:
    //Map with key our Val and its amount
    std::unordered_map<int, int> elementCount;
    int maxVal = 0;

    void mapValues(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        //increment the element count
        elementCount[root->val]++;

        if(elementCount[root->val] > maxVal){
            maxVal = elementCount[root->val];
        }
        //call it on every Node
        mapValues(root->left);
        mapValues(root->right);
    }
    std::vector<int> findMode(TreeNode* root) {
        std::vector<int> modes;
        mapValues(root);
        //take the max frequency Val
        for (const auto& entry : elementCount) {
            if (entry.second == maxVal) {
                modes.push_back(entry.first);
            }
        }
        return modes;
    }
};