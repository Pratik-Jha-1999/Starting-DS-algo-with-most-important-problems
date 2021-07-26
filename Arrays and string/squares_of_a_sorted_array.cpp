#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    int b[n];
    int k=n-1;
    
    int i=0,j=n-1;
    while(i<=j)
    {
        if(a[i]*a[i]>a[j]*a[j])
        {b[k]=a[i]*a[i];
        k--;i++;}
        else
        {
            b[k]=a[j]*a[j];
            k--;j--;
        }
    }
    for(int i=0;i<n;i++)
    cout<<b[i]<<" ";
  
    
    
    return 0;
}