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
*root=getnode(data);

else
{
    if(data<=(*root)->data)
    addnode(&(*root)->left,data);

    else addnode(&(*root)->right,data);
}
}

void reverse_level_order(Node* root)
{
queue<Node*> q;
vector<int> v;

q.push(root);
while(!q.empty())
{
    if(q.front()->right)
    q.push(q.front()->right);
    if(q.front()->left)
    q.push(q.front()->left);
    
    v.push_back(q.front()->data);
    q.pop();
}

reverse(v.begin(),v.end());
for(int i:v)
cout<<i<<" ";
}


int main()
{

Node* root=NULL;
addnode(&root,10);
addnode(&root,12);
addnode(&root,1);
addnode(&root,7);
addnode(&root,18);
addnode(&root,15);
reverse_level_order(root);



    return 0;
}