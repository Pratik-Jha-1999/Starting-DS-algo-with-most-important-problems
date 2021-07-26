#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    int q;
    cin>>q;
    int updates[q][3];
    for(int i=0;i<q;i++)
    for(int j=0;j<3;j++)
    cin>>updates[i][j];
   
   int c=0;
   while(c<q)
   {
       a[updates[c][0]]+=updates[c][2];
       a[updates[c][1]+1]-=updates[c][2];
       c++;
   }

for(int i=1;i<n;i++)
{
    a[i]+=a[i-1];
}
for(int i=0;i<n;i++)
cout<<a[i]<<" ";

    return 0;
}