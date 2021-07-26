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

vector<int> ans;

bool find(Node* root, int data)
{   
    if(root==NULL)
    return false;
    
    if(root->data==data)
    {ans.push_back(root->data);
    return true;
    }

    if(find(root->left,data))
    {ans.push_back(root->data);
    return true;
    } 

    if(find(root->right,data))
    {ans.push_back(root->data);
    return true;
    }

    return false;

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

cout<<find(root,21);
for(int i:ans)
cout<<i<<" ";
//levelorder(root);

    return 0;
}