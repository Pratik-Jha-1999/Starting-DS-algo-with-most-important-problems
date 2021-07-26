#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;
};

Node* getnode(int data)
{
    Node* newnode=new Node();
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
}

void addtree(Node** root, int data)
{
    if(*root==NULL)
    *root=getnode(data);

    else{
        if((*root)->data>=data)
        addtree(&(*root)->left,data);

        else 
        addtree(&(*root)->right, data);
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

vector<Node*> v;
void k_Nodes_down(Node* root, int k, Node* blocker)
{
    if(root==NULL||k<0||root==blocker)
    return;
   

    if(k==0){
    v.push_back(root);
    return;}


   k_Nodes_down(root->left,k-1,blocker);
   k_Nodes_down(root->right,k-1,blocker);

}

vector<Node*> path;
bool Node_to_root(Node* root, int data)
{   
   if(root==NULL)
   return false;

   if(root->data==data)
   {
       path.push_back(root);
       return true;
   }

   if(Node_to_root(root->left,data))
   {path.push_back(root);
   return true;
   }

   if(Node_to_root(root->right,data))
   {path.push_back(root);
   return true;
   }

   return false;
  
}


void k_distance_far(Node* root, int data,int k)
{
    Node_to_root(root,data);
    int i=0;
    Node* m=NULL;
    for(Node* n:path)
    {k_Nodes_down(n,k-i,m);
    i++;
    m=n;
    }
}



int main()
{

Node* root=NULL;
addtree(&root,10);
addtree(&root,5);
addtree(&root,17);
addtree(&root,4);
addtree(&root,8);
addtree(&root,20);
addtree(&root,1);
addtree(&root,6);
addtree(&root,9);
addtree(&root,18);
//levelorder(root);
/*k_Nodes_down(root,2);
cout<<endl;
for(Node* n:v)
cout<<n->data<<" ";

cout<<endl;
Node_to_root(root,30);
for(Node* n:path)
cout<<n->data<<" ";*/
k_distance_far(root,8,3);

for(Node* n:v)
cout<<n->data<<" ";
    return 0;
}