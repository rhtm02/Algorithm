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
#include <map>

using namespace std;
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        
        queue<queue<TreeNode*>> q;
        map<int,int> valDepth;
        queue<TreeNode*> temp;
        temp.push(root);
        q.push(temp);
        int depth = 0;
        
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            TreeNode* tempnode;
            queue<TreeNode*> innerQ;
            while(!temp.empty())
            {
                tempnode = temp.front();
                temp.pop();
                if(tempnode == nullptr) continue;
                valDepth[tempnode->val] = depth;
                innerQ.push(tempnode->left);
                innerQ.push(tempnode->right);
            }
            depth++;
            if(!innerQ.empty()) q.push(innerQ);
        }
        
        queue<TreeNode*> q2;
        q2.push(root);
        map<int,int> valParent;
        TreeNode* temp2;
        while(!q2.empty())
        {
            temp2 = q2.front();
            q2.pop();
            if(temp2 == nullptr) continue;
            if(!(temp2->left == nullptr)) valParent[temp2->left->val] = temp2->val;
            if(!(temp2->right == nullptr)) valParent[temp2->right->val] = temp2->val;
            q2.push(temp2->right);
            q2.push(temp2->left);
        }
        /*
        for(auto it:valDepth)
        {
            cout << it.first << " " << it.second << endl;
        }
        for(auto it:valParent)
        {
            cout << it.first << " " << it.second << endl;
        }
        */
        return (valDepth[x] == valDepth[y]) && (valParent[x] != valParent[y]);
    }
};