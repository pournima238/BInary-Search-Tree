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
    void inorder(TreeNode* root, vector<int>&in){
       if(root==NULL){
           return;
       } 
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    bool findTarget(TreeNode* root, int k) {
      vector<int>in;
      inorder(root,in); 
        //first store the bst in vector
        //vector is sorted so using two pointer approach
        for(int i=0; i<in.size();i++){
            cout<<in[i]<<" ";
        }
      int s=0, e=in.size()-1;
      while(s<e){
          int sum=in[s]+in[e];
          if(sum>k){
              e--;
          }
          if(sum<k){
              s++;
          }
          if(sum==k){
              return true;
          }
          
      } 
        return false;
    }
};