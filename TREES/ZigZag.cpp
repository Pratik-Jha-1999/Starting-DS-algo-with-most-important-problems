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
Node* newnode= new Node();
newnode->left=NULL;
newnode->right=NULL;

newnode->data=data;

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

void zigzag(Node* root)
{
queue<Node*> q;
vector<int> ans;
q.push(root);
int sz=q.size();
int k=1;
while(!q.empty())
{vector<int> t;
while(sz--)
{
if(q.front()->left)
q.push(q.front()->left);

if(q.front()->right)
q.push(q.front()->right);

t.push_back(q.front()->data);
q.pop();
}
if(k==0)
reverse(t.begin(),t.end());

for(int i:t)
ans.push_back(i);

k=!k;
sz=q.size();
}
for(int i:ans)
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
    
zigzag(root);


    return 0;
}