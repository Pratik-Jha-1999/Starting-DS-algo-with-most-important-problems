#include<iostream>
using namespace std;



int main()
{
int n;
cin>>n;
int t[n+1];
t[0]=1;
t[1]=1;

for(int i=2;i<n+1;i++)
t[i]=0;

for(int i=2;i<n+1;i++)
{
    for(int j=0;j<i;j++)
    t[i]+=t[j]*t[i-j-1];
}


cout<<t[n];

    return 0;
}