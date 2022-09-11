#include <bits/stdc++.h>
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
    int min(TreeNode* root){
        if(root->left==NULL){
            return root->val;
        }
        return min(root->left);
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
       if(root==NULL){
           return root;
       } 
        if(root->val==key){
            //0 child
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            //1 child
            if(root->left!=NULL && root->right==NULL){
               TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            if(root->left==NULL && root->right!=NULL){
               TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            //2 child case
            if(root->left!=NULL && root->right!=NULL){
                int minValue=min(root->right);
                root->val=minValue;
                root->right=deleteNode(root->right,minValue);
                return root;
            }
        }
        if(root->val>key){
            root->left=deleteNode(root->left,key);
            return root;
        }else if(root->val<key){
            root->right=deleteNode(root->right,key);
            return root;
        }
        return root;
    }
};