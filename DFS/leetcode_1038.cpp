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
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int sumofVector = 0;
    
    TreeNode* bstToGst(TreeNode* root) { 
        queue<TreeNode*> q;
        TreeNode* temp;
        q.push(root);
        
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            if(temp == nullptr) continue;
            sumofVector += temp->val;
            q.push(temp->left);
            q.push(temp->right);
        }
                
        inorderAlgorithm(root);
        
        return root;
    }
    
    void inorderAlgorithm(TreeNode* inputs)
    {
        if(inputs == nullptr) return;
        int temp = 0;
        inorderAlgorithm(inputs->left);
        temp = sumofVector - inputs->val; 
        inputs->val += (temp);
        sumofVector = temp;
        inorderAlgorithm(inputs->right);
    }
};