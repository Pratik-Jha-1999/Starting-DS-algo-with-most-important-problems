#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node *left,*right;
};

Node* getnode(int data)
{Node* newnode= new Node();
newnode->data=data;
newnode->left=NULL;
newnode->right=NULL;
return newnode;
}
 
void addnode(Node** root, int data)
{
  if(*root==NULL)
  *root=getnode(data);
  else
  {
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

void print_k_levels_down(Node* root, int k)
{
    if(root==NULL)
    return ;
    if(k==0)
    {cout<<root->data<<" ";
    return ;
    }

    print_k_levels_down(root->left,k-1);
    print_k_levels_down(root->right,k-1);
    
}


int main()
{
Node* root=NULL;
addnode(&root,2);
addnode(&root,3);
addnode(&root,8);
addnode(&root,1);
addnode(&root,19);
addnode(&root,12);
addnode(&root,21);

print_k_levels_down(root,1);

    return 0;
}