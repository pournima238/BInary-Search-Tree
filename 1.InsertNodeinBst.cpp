#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
    this->data=d;
    this->left=NULL;
    this->right=NULL;
    }
};
node* InsertToBst(node* root, int data){
    if(root==NULL){
        root=new node(data);
        return root;
    }
    if(root->data > data){
       root->left=InsertToBst(root->left, data);
    }
    if(root->data< data){
        root->right=InsertToBst(root->right, data);

    }
    //to return start root node
    return root;

}
void takeInput(node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=InsertToBst(root, data);
        cin>>data;
    }
}

void inorder(node* root){
    //LNR
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<< " ";
    inorder(root->right);


}
int main(){
    node* root=NULL;
    cout<<"enter the elements to be inserted in bst"<<endl;
    takeInput(root);
    inorder(root);

}