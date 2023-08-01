#include<bits/stdc++.h>
using namespace std;


/* A binary tree node has data, pointer to left child
   and a pointer to right child  
*/
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

//Function to return a list containing the level order traversal in spiral form.
vector<int>findSpiral(Node *root)
{
    //Your code here
    
    // Flag will handle all the requirement
    vector<int>ans;
    queue<Node *>q;
    q.push(root);
    int flag = false;
    while(!q.empty()){
        int n = q.size();
        vector<int>temp;
        while(n--){
            auto front = q.front(); // node so auto
            q.pop();
            temp.push_back(front -> data);
            if(front -> left) 
            {
                q.push(front -> left);
            }
            if(front -> right)
            {
                q.push(front -> right);
            }
        }
        if(!flag) reverse(temp.begin() , temp.end());

        for(auto it : temp)
            ans.push_back(it);
        
        flag = 1 - flag ; // it will twick : )
    }
    return ans;
}

void count(Node * root , int &cnt){
    if(!root) return;
    count(root -> left , cnt);
    cnt++;
    count(root -> right , cnt);
}

// . inorder traverse 