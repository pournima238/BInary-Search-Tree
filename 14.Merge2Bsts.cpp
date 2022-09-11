#include<bits/stdc++.h>
using namespace std;
    template <typename T>
    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
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
TreeNode<int> *makeBST(vector<int>& merger, int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    TreeNode<int> *temp=new TreeNode<int>(merger[mid]);
    temp->left=makeBST(merger, s, mid-1);
    temp->right=makeBST(merger,mid+1,e);
    return temp;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    //saving two bsts in two diffrent vectors inorderly
  vector<int>bst1;
  vector<int>bst2;
  vector<int>merger;
   inorderV(root1, bst1);
   inorderV(root2,bst2);
    //merging two vectors into one
    int i=0;
    int j=0;
    while(i<bst1.size() && j<bst2.size()){
        if(bst1[i]>bst2[j]){
            merger.push_back(bst2[j++]);
        }else{
            merger.push_back(bst1[i++]);
        }
    }
    while(i<bst1.size()){
        merger.push_back(bst1[i++]);
    }
     while(j<bst2.size()){
        merger.push_back(bst2[j++]);
    }
    //now we make bst from sorted list
   return makeBST(merger,0,merger.size()-1);
    
}