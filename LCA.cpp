/*
    Brute Force == traverse till you get the node and store the middle ones
    (4 , 7) = 1 , 2 ,3 ,4
            = 1 ,2 ,3, 5 ,7
    
    loop till != (return the before one)

    // Normal approch Recursion
     see code
*/



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

class Solution{
    public:
        Node* LCA(Node *root, int n1, int n2)
        {
            // Base case condition

            if(root == NULL || root -> data == n1 || root -> data == n2){
                return root;
            }

            // call recursion
            Node * left = LCA(root -> left , n1 , n2 );
            Node * right = LCA(root -> right , n1 , n2);

            //handle NULL condition
            if(left == NULL)
                return right;

            if(right == NULL)
                return left;
            
            else 
                return root;
        }
};