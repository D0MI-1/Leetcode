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
**/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue> 
#include <unordered_set> 
#include "solution.h"

class Solution {
private:
    std::unordered_map<int, std::vector<int>> graph;

public:
    int amountOfTime(TreeNode* root, int start) {
        constructGraph(root);

        std::queue<int> q; // Add std:: for std::queue
        q.push(start);

        std::unordered_set<int> visited; // Add std:: for std::unordered_set

        int minutesPassed = -1;

        // BFS to simulate the infection spread
        while (!q.empty()) {
            ++minutesPassed;
            for (int levelSize = q.size(); levelSize > 0; --levelSize) {
                int currentNode = q.front();
                q.pop();
                visited.insert(currentNode);
                for (int adjacentNode : graph[currentNode]) {
                    if (!visited.count(adjacentNode)) {
                        q.push(adjacentNode);
                    }
                }
            }
        }

        return minutesPassed;
    }

    void constructGraph(TreeNode* root) {
        if (!root) return;

        // Add edges between the current node and its children to the graph
        if (root->left) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }

        if (root->right) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }

        // Recursive calls for the children
        constructGraph(root->left);
        constructGraph(root->right);
    }
};
