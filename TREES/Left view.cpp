#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node{
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
    *root=getnode(data);

    else{
        if(data<=(*root)->data)
        addnode(&(*root)->left,data);
        else 
        addnode(&(*root)->right,data);
        }

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

void leftview(Node* root)
{
queue<Node*> q;
q.push(root);
while(!q.empty())
{   int sz=q.size();
     cout<<q.front()->data<<" ";

    while(sz--)
    { Node* t=q.front();
      q.pop();

      if(t->left)
      q.push(t->left);  
      if(t->right)
      q.push(t->right);   
    }
  
}

}
int main()
{
Node* root=NULL;
addnode(&root, 50);
addnode(&root, 20);
addnode(&root, 70);
addnode(&root, 15);
addnode(&root, 30);
addnode(&root, 55);
addnode(&root, 90);
addnode(&root, 10);
addnode(&root, 25);
addnode(&root, 35);
addnode(&root, 75);
levelorder(root);
cout<<endl;
leftview(root);
    return 0;
}