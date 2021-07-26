#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left, *right;
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

int height(Node* root)
{
  if(root==NULL)
  return -1;
  

  return max(height(root->left),height(root->right))+1;
}

/*
int diameter(Node* root)                 //inefficient due to recursive call of height in recursive call of diameter 
{
  if(root==NULL)
  return 0;
  
   int dl= diameter(root->left);
   int dr= diameter(root->right);
    
    
   int cd=height(root->left)+height(root->right)+2;
   return max(cd,max(dl,dr));

}
*/
class diapair{
public:
int h;
int d;
};

diapair diameter(Node *root)
{
    if(root==NULL)
    {
        diapair sd;
        sd.h=-1;
        sd.d=0;
        return sd;
    }


    diapair ld=diameter(root->left);
    diapair rd=diameter(root->right);

    diapair sd;
    sd.d=max((ld.h+rd.h+2),max(ld.d,rd.d));
    sd.h=max(ld.h,rd.h)+1;
    return sd;
}




int main()
{
Node* root=NULL;
addnode(&root,50);
addnode(&root,20);
addnode(&root,70);
addnode(&root,15);
addnode(&root,30);
addnode(&root,55);
addnode(&root,90);
addnode(&root,10);
addnode(&root,25);
addnode(&root,35);
addnode(&root,75);

levelorder(root);

cout<<endl;
diapair ans=diameter(root);
cout<<ans.d;
    return 0;
}