/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#include <queue>
using namespace std;
class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr) return 0;
        queue<queue<Node*>> q;
        queue<Node*> inner_q;
        Node* temp;
        
        inner_q.push(root);
        q.push(inner_q);
        inner_q.pop();
        
        int cnt = 0;
        while(!q.empty())
        {
            inner_q = q.front();
            q.pop();
            Node* temp;
            queue<Node*> temp_inner_q;
            while(!inner_q.empty())
            {
                temp = inner_q.front();
                inner_q.pop();
                if(temp == nullptr) continue;
                for(auto it:temp->children)
                {
                    temp_inner_q.push(it);
                    //cout<<it->val<<endl;
                }
                //cout<<"==============="<<endl;
            }
            if(temp_inner_q.size() == 0) continue;
            q.push(temp_inner_q);
            cnt++;
        }
        cout << cnt << endl;
        return cnt + 1;
    }
};