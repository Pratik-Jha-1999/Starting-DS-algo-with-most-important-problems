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
    
    if(n<3)
    return 0;
    
    int min1=INT_MAX;
    int min2=INT_MAX;
    int max1=INT_MIN;
    int max2=INT_MIN;
    int max3=INT_MIN;
    
    for(int i=0;i<n;i++)
    {
        if(a[i]>=max1)
        {
            max3=max2;
            max2=max1;
            max1=a[i];
        }
        else if(a[i]>=max2)
        {
            max3=max2;
            max2=a[i];
        }
        else if(a[i]>=max3)
        max3=a[i];
        
        if(a[i]<=min1)
        {
            min2=min1;
            min1=a[i];
        }
        else if(a[i]<=min2)
        min2=a[i];
    }
    
    cout<<max((max1*max2*max3),(min1*min2*max1));
    
    return 0;
}