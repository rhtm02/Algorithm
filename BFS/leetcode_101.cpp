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
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        vector<int> bfsList;
        
        bfsList = BFS(root);
        printVector(bfsList);

     
        return true;  
    }    
    
    vector<int> BFS(TreeNode* &inputs)
    {
        vector<int> output;
        queue<TreeNode*> searchList;
        
        searchList.push(inputs->left);
        searchList.push(inputs->right);
        output.push_back(inputs->val);
        TreeNode* temp;
        //BFS
        while(!searchList.empty())
        {
            temp = searchList.front();
            searchList.pop();
            output.push_back(temp->val);
            if(temp->left != nullptr) searchList.push(temp->left);
            if(temp->right != nullptr) searchList.push(temp->right);
        }
        
        return output;
    }
    
    bool Symmetric(vector<int> &inputs)
    {

        return true;
    }
    
    void printVector(vector<int> &inputs)
    {
        for(auto it: inputs)
        {
            cout<<it<<endl;
        }
    }
};