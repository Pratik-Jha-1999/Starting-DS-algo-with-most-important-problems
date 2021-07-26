#include<iostream>
using namespace std;

int main()
{
    
    int n;
    cin>>n;
    int val[n];
    for(int i=0;i<n;i++)
    cin>>val[i];
    
    int wt[n];
    for(int i=0;i<n;i++)
    cin>>wt[i];
    
    int cap;
    cin>>cap;
    
    int t[n+1][cap+1];
    
    for(int i=0;i<n+1;i++)
    for(int j=0;j<cap+1;j++)
    {
        if(i==0||j==0)
        t[i][j]=0;
        
        else if(wt[i-1]<=j)
        t[i][j]=max(t[i-1][j],val[i-1]+t[i][j-wt[i-1]]);
        
        else 
        t[i][j]=t[i-1][j];
        
    }
    
    cout<<t[n][cap];
    
    
    return 0;
}