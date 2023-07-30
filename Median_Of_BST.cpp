/*
    traverse Inorder
    return midean idx
*/

#include<bits/stdc++.h>
using namespace std;


// Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// your task is to complete the Function
// Function should return median of the BST

void inorder(vector<int> &store , Node * root){
    // In-Order  --- > Call -- Push -- Call
    if(!root) return;

    inorder(store , root -> left);
    store.push_back(root -> data);
    inorder(store , root -> right);
}

float findMedian(struct Node *root)
{
      //Code here
      vector<int>store;
      inorder(store , root);

      int n = store.size();

      if(n%2 == 0){
        int x = store[n / 2];
        int y = store[n/2 - 1];

        return (float)((x+y) / 2);
      }
      return store[n/2];
}