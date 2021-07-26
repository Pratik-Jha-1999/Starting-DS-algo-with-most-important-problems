#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//similar to Largest increasing subsequence
int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  cin>>a[i];

  int t[n];
  t[0]=a[0];
  int sum=INT_MIN;
  int ans=a[0];
  for(int i=1;i<n;i++)
  {
      for(int j=0;j<i;j++)
      {if(a[i]>=a[j])
      sum=max(sum,t[j]);
      }
     t[i]=sum+a[i];
     sum=INT_MIN;
     ans=max(ans,t[i]);
  }
if(n!=0)
cout<<ans;

    return 0;
}