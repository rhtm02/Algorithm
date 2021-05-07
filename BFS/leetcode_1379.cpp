/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue>

using namespace std;
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> q;
        
        q.push(original);
        q.push(cloned);
        TreeNode* temp;
        TreeNode* temp2;
        
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            temp2 = q.front();
            q.pop();
            if(temp == nullptr) continue;
            if(temp->val == target->val) break; 
                        
            q.push(temp->left);
            q.push(temp2->left);
            q.push(temp->right);
            q.push(temp2->right);
        }
        return temp2;
    }
};