#include<bits/stdc++.h>
using namespace std;

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };



pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    BinaryTreeNode<int>* temp=root;
    int pred=-1;
    int succ=-1;
    while(temp->data!=key){
        if(temp->data>key){
            succ=temp->data;
            temp=temp->left;
        }else{
            pred=temp->data;
            temp=temp->right;
        }
        
    }
    
    //pred=>max value in left subtree
    BinaryTreeNode<int>* leftSubtree=temp->left;
    while(leftSubtree!=NULL){
        pred=leftSubtree->data;
        leftSubtree=leftSubtree->right;
    }
    //succ->min value in right subtree
      BinaryTreeNode<int>* rightSubtree=temp->right;
    while(rightSubtree!=NULL){
        succ=rightSubtree->data;
        rightSubtree=rightSubtree->left;
    }
    
    return {pred, succ};
    
    
    
}
