#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 

// Should return  right view of tree
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       queue<Node *> q;
       vector<int>ans;
       q.push(root);
       
       while(!q.empty())
       {
           int sz = q.size();
           for(int i = 0 ; i < sz ; ++i)
           {
               Node * temp = q.front();
               q.pop();
               
               if(i == 0) ans.push_back(temp -> data); // only pushh the start node
               if(temp -> right) q.push(temp -> right);
               if(temp -> left) q.push(temp -> left);
            }
       }
       return ans;
    }
};
