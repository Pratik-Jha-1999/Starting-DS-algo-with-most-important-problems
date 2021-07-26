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

class isbal
{
    public:
    bool is;
    int h;
};

isbal isbalanced(Node* root)
{
    if(root==NULL)
    {
        isbal self;
        self.h=-1;
        self.is=true;

        return self;
    }

    isbal isl=isbalanced(root->left);
    isbal isr=isbalanced(root->right);
    
    isbal self;
    self.h=max(isl.h,isr.h)+1;
    
    if(abs(isl.h-isr.h)<2&&isl.is&&isr.is)
    self.is=true;
    else self.is=false;
    return self;
}

void levelorder(Node* root)
{
  queue<Node*> q;
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
    
addnode(&root,50);
addnode(&root,20);
addnode(&root,70);
addnode(&root,15);
//addnode(&root,30);
addnode(&root,55);
addnode(&root,90);
addnode(&root,10);
//addnode(&root,25);
//addnode(&root,35);
addnode(&root,75);
levelorder(root);
cout<<endl;
isbal ans=isbalanced(root);
cout<<ans.is;
    return 0;
}