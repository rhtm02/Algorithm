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
#include <queue>

using namespace std;
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* leftSide;
        TreeNode* rightSide;
        
        q.push(root);
        q.push(root);
        
        while(!q.empty())
        {

            leftSide = q.front();
            q.pop();
            rightSide = q.front();
            q.pop();
            
            if ((leftSide == nullptr) ^ (rightSide == nullptr)) return false;
            else if((leftSide == nullptr) && (rightSide == nullptr)) continue;
            if(leftSide->val != rightSide->val) return false;
            
            q.push(leftSide->right);
            q.push(rightSide->left);
            
            q.push(leftSide->left);
            q.push(rightSide->right);
        }
        
        return true;  
    }    
};