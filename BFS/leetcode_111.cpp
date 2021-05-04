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
using namespace std;
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        if((root->left == nullptr) && (root->right == nullptr)) return 1;
        
        else if((root->left != nullptr) && (root->right == nullptr))
        {
            return 1 + minDepth(root->left);
        }
        else if((root->left == nullptr) && (root->right != nullptr))
        {
            return 1 + minDepth(root->right);
        }
        return 1 + min(minDepth(root->right),minDepth(root->left));
        
    }
};