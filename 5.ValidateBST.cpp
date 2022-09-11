#include <bits/stdc++.h>
using namespace std;
 // Definition for a binary tree node.
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
    bool isValid(TreeNode* root, long min, long max){
        if(root==NULL){
            return true;
        }
        if( root->val > min && root->val< max){
            bool isleft=isValid(root->left,min,root->val);
            bool isRight=isValid(root->right,root->val,max);
            return isleft&& isRight;
            
        }else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        if(root->left==NULL && root->right==NULL){
            return true;
        }
       
        return isValid(root,LONG_MIN,LONG_MAX);
        
    }
};