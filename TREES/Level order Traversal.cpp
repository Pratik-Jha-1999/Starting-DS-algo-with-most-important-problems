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
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
}

void addnode(Node** root, int data)
{
    if(*root==NULL)
    {*root=getnode(data);
    return ;}
    
   if(data<=(*root)->data)
   addnode(&(*root)->left, data);
   else
   addnode(&(*root)->right, data);
   
}


void printtree(Node* root)
{
    if(root==NULL)
    return ;

    printtree(root->left);
    printtree(root->right);
    cout<<root->data<<" ";
}

void levelorder(Node* root)
{
    queue<Node*> q;
    if(root!=NULL)
    q.push(root);
    while(!q.empty())
    {
    if(q.front()->left)
    q.push(q.front()->left);

    
    if(q.front()->right)
    q.push(q.front()->right);

    cout<<q.front()->data<<" ";
    q.pop();
    }

}




int main()
{
Node* root=NULL;
addnode(&root,10);
addnode(&root,1);
addnode(&root,15);
addnode(&root,5);
addnode(&root,11);


//printtree(root);
levelorder(root);



    return 0;
}