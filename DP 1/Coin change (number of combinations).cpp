#include<iostream>
using namespace std;

// given infinite supply of coins of each denomination, find maximum ways we can pay an amount

int main()
{
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];

int K;
cin>>K;

int t[n+1][K+1];
for(int i=0;i<K+1;i++)
t[0][i]=0;

for(int i=0;i<n+1;i++)
t[i][0]=1;

for(int i=1;i<n+1;i++)
for(int j=1;j<K+1;j++)
{if(a[i-1]<=j)
 t[i][j]=t[i-1][j]+t[i][j-a[i-1]];
 else 
 t[i][j]=t[i-1][j];
}

cout<<t[n][K];
    return 0;
}