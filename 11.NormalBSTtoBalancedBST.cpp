#include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& in){
        if(root==NULL){
            return;
        }
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    TreeNode* newBST(int s, int e, vector<int>&in){
        if(s>e){
            return NULL;
        }
        int mid=(s+e)/2;
        TreeNode* temp= new TreeNode(in[mid]);
        temp->left=newBST(s, mid-1,in);
        temp->right=newBST(mid+1,e,in);
        
        return temp;
    }
    TreeNode* balanceBST(TreeNode* root) {
        //approach->store inorder in vector and make the bst
        vector<int>in;
        inorder(root, in);
         return newBST(0,in.size()-1,in);
        
    }
};