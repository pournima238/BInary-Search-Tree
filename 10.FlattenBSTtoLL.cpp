#include<bits/stdc++.h>
using namespace std;
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };


void inorderV(TreeNode<int>* root, vector<int>&ll){
    if(root==NULL){
        return;
    }
    inorderV(root->left, ll);
    ll.push_back(root->data);
    inorderV(root->right, ll);
    
}
TreeNode<int>* flatten(TreeNode<int>* root)
{//approach used is store inorder in vector and make new nodes whose left pointer points null and right pointer point to the next node.
   vector<int>ll;
    inorderV(root, ll);
    int n=ll.size();
    TreeNode<int>* newRoot=new TreeNode<int>(ll[0]);
    TreeNode<int>* curr=newRoot;
    for(int i=1; i<n; i++){
      TreeNode<int>* temp=new TreeNode<int>(ll[i]);
      curr->left=NULL;
      curr->right=temp;
      curr=temp;
    }
    curr->left=NULL;
    curr->right=NULL;
    return newRoot;
}
