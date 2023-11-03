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

//von unten nach Oben
class Solution {
public:
    int counter = 0;

    std::pair<int, int> calculateSubtreeSum(TreeNode* Node) {
        if (Node == nullptr)
            return {0, 0}; 
        //calculate left and right Node sum if we get to the last one ...
        auto leftSubtree = calculateSubtreeSum(Node->left);
        auto rightSubtree = calculateSubtreeSum(Node->right);
        //... we add the result to our Nodes above
        int sum = leftSubtree.first + rightSubtree.first + Node->val;
        int numberOfNodes = leftSubtree.second + rightSubtree.second + 1;
        //and then we check for the avg and if its the same to val we increment our counter
        if (sum / numberOfNodes == Node->val)
            counter++; 

        return {sum, numberOfNodes};
    }

    int averageOfSubtree(TreeNode* root) {
        calculateSubtreeSum(root);
        return counter; 
    }
};