#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node *left, *right;
};


Node* getnode(int data)
{

    Node* newnode=new Node();
    newnode->left=NULL;
    newnode->right=NULL;

    newnode->data=data;
    return newnode;
}


void addnode(Node** root, int data)
{   
    if(*root==NULL)
     {*root=getnode(data);
        return;}


     if(data<=(*root)->data)
     addnode(&(*root)->left,data);
     else 
     addnode(&(*root)->right,data);

}

void print_tree(Node* root)
{
if(root==NULL)
return;

print_tree(root->left);
print_tree(root->right);
cout<<root->data<<" ";

}


class Bstpair
{
public:
int max;
int min;
bool is;
};


Bstpair isbst(Node* root)
{
if(root==NULL)
{
    Bstpair mi;
    mi.max=INT_MIN;
    mi.min=INT_MAX;
    mi.is=true;
     
    return mi;
}

Bstpair l=isbst(root->left);
Bstpair r=isbst(root->right);

Bstpair mi;

if(l.is&&r.is&&root->data>l.max&&root->data<r.min)
mi.is=true;
else 
mi.is=false;

mi.min=min(root->data,l.min);
mi.max=min(root->data,r.max);

return mi;

}



int main()
{

    Node* root=NULL;
    /*addnode(&root, 4);
    addnode(&root, 7);
    addnode(&root, 1);
    addnode(&root, 5);
    addnode(&root, 3);
    addnode(&root, 2);
    */
   root=new Node();
root->data=10;
root->right=new Node();
root->left= new Node();

root->left->data=15;
root->right->data=2;
root->left->left=NULL;
root->left->right=NULL;
root->right->left=NULL;
root->right->right=NULL;


 print_tree(root);

Bstpair ans=isbst(root);
if(ans.is)
cout<<"yes it is a BST";
else 
cout<<"No is is not ";
    return 0;
}