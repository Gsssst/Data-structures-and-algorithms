#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

typedef struct node{
    int val;
    node *l,*r;
}*Node;

Node add(int x){
    Node temp = new node;
    temp->val = x;
    temp->l = nullptr;
    temp->r = nullptr;
    return temp;
}

Node insert(Node root,int x){
    if(!root) return add(x);
    if(x>root->val) root->r = insert(root->r,x);
    else if(x<root->val) root->l = insert(root->l,x);
    return root;
}

void pre(Node root){
    if(!root) return ;
    cout<<root->val<<" ";
    pre(root->l);
    pre(root->r);
}
void in(Node root){
    if(!root) return ;
    in(root->l);
    cout<<root->val<<" ";
    in(root->r);
}
void post(Node root){
    if(!root) return ;
    post(root->l);
    post(root->r);
    cout<<root->val<<" ";
}

int n;
Node root = nullptr;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        root = insert(root,temp);
    }
    pre(root);
    cout<<endl;
    in(root);
    cout<<endl;
    post(root);
    cout<<endl;
    return 0;
}
