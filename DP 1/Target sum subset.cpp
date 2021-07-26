#include<iostream>
using namespace std;


int main()
{

int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];

int K;
cin>>K;

bool t[31][51];
for(int i=0;i<K+1;i++)
t[0][i]=false;

for(int i=0;i<n+1;i++)
t[i][0]=true;

for(int i=1;i<n+1;i++)
for(int j=1;j<K+1;j++)
{if(a[i-1]<=j)
 t[i][j]=t[i-1][j]||t[i-1][j-a[i-1]];
 else 
 t[i][j]=t[i-1][j];
}
if(t[n][K])
cout<<"true";
else cout<<"false";



    return 0;
}