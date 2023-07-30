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

void count(Node * root , int &cnt){
    if(!root) return;
    count(root -> left , cnt);
    cnt++;
    count(root -> right , cnt);
}

void check(Node * root , Node * &curr , Node * &prev , int &cnt , int x , int &found){

    if(!root) return;
    check(root -> left , curr , prev , cnt , x , found);

    // 3 condition can happen 
    // NULL ,  found  , not found
    if(prev == NULL){ // first assign right
        prev = root;
        cnt++;
    }
    else if(cnt == x){
        cnt++;
        curr = root;
        found = 1;
        return;
    }
    else if(found == 0){
        prev = root;
        cnt++;
    }

    check(root -> right , curr , prev , cnt , x , found);
}

float findMedian(struct Node *root)
{
    int cnt = 0;
    count(root , cnt);

    // for even cnt
    Node * curr = NULL;
    Node * prev = NULL;

    int c = 1;
    int x = (cnt / 2) + 1;

    int found = 0;
    check(root , curr , prev , c , x , found);

    if(cnt % 2 == 0){
        float ans = ((curr -> data + prev -> data) * 1.0) / (2 * 1.0);
        return ans;
    }
    else{
        float ans = (curr -> data) * 1.0;
        return ans;
    }
}