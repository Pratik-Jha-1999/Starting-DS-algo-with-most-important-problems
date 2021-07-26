#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minimum_cost(int a[], int b, int e )
{
  if(b>=e)
  return 0;
  
  int cost=INT_MAX;

  for(int k=b;k<e;k++)
  cost=min(a[b-1]*a[k]*a[e]+minimum_cost(a,b,k)+minimum_cost(a,k+1,e),cost);
  

return cost;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    cout<<minimum_cost(a,1,n-1);
    return 0;
}