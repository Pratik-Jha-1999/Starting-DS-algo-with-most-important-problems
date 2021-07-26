#include<iostream>
using namespace std;

int main()
{
int n;
cin>>n;
int a[n];
for (int i = 0; i < n; i++)
{
    cin>>a[i];
}
int K;
cin>>K;
int t[K+1];
for(int i=0;i<K+1;i++)
t[i]=0;

t[0]=1;

for(int i=1;i<K+1;i++)
{for(int j=0;j<n;j++)
if(a[j]<=i)
t[i]+=t[i-a[j]];
}

cout<<t[K];

    return 0;
}