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
    
    int w=0;
    
    int i=0,j=n-1;
    while(i<j)
    {
        w=max(min(a[i],a[j])*(j-i),w);
        if(a[i]<a[j])
        i++;
        else 
        j--;
    }
    
    cout<<w;
    return 0;
}