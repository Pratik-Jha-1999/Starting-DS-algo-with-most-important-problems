#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
   
    if(s.size()<2)
    {
        cout<<-1;
        return 0;
    }
    
    int i,j;
    for(i=s.size()-2;i>=0;i--)
    {
        if(s[i]<s[i+1])
        break;
    }
    
    if(i==-1)
    {cout<<-1;
     return 0;
    }
    
    for(j=s.size()-1;j>i;j--)
    if(s[j]>s[i])
    break;
    
    int t=s[i];
    s[i]=s[j];
    s[j]=t;
    
    for(int l=i+1,r=s.size()-1;r>l;l++,r--)
    {
        t=s[l];
        s[l]=s[r];
        s[r]=t;
    }
    cout<<s; 
    
    return 0;
}