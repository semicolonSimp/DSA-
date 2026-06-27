#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
     
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
Node* leftsubrightval(Node* root){
    Node* ans;
    while(root!=NULL){
        ans=root;
        root=root->right;
    }
    return ans;
}
Node* rightsubleftval(Node* root){
    Node* ans;
    while(root!=NULL){
        ans=root;
        root=root->left;
    }
    return ans;
}
vector<int>getpreandsu(Node*root,int &key){
    Node* curr=root;
    Node* pred=NULL;
    Node* succ=NULL;
    while(curr!=NULL){
        if(key<curr->data){
            succ=curr;
            curr=curr->left;
        }
        else if(key>curr->data) {
            pred=curr;
            curr=curr->right;
        }else{
            //inorderpredecesor->lefatmost subtree with rightvalue
            if(curr->left!=NULL){
                pred=leftsubrightval(curr->left);
            }
            if(curr->right!=NULL){
                succ=rightsubleftval(curr->right);
            }
            break;
        }  
    }
    return {pred->data,succ->data};
}
int main(){
    Node* root=new Node(6);
    root->left=new Node(4);
    root->right=new Node(8);
    root->left->left=new Node(1);
    root->left->right=new Node(5);
    root->right->left=new Node(7);
    root->right->right=new Node(9);
    int key=7;
    vector<int>ans=getpreandsu(root,key);
    cout<<"inorder predecesor :"<<ans[0]<<endl;
    cout<<"inorder successor :"<<ans[1]<<endl;
    return 0;

}