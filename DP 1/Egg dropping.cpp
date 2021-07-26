#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int minimum_attempts(int e,int f)
{
if(e==0)
return 0;
if(f==0)
return 0;
if(f==1)
return 1;
if(e==1)
return f;
int mini=INT_MAX;

int maxi;
for(int i=1;i<=f;i++)
{maxi=max(minimum_attempts(e,f-i),minimum_attempts(e-1,i-1));
mini=min(mini,maxi);
}

return mini+1;
}


void by_tabulation(int e,int f)
{
    int t[e+1][f+1];
    for(int i=0;i<e+1;i++)
    for(int j=0;j<f+1;j++)
    {
        if(j==0)
        t[i][j]=0;
        else
        if(i==1)
        t[i][j]=j;
        else
        if(j==1)
        t[i][j]=1;

        else
       {
           t[i][j]=INT_MAX;
           for(int cj=j-1, pj=0;cj>=0;cj--,pj++)
           t[i][j]=min(max(t[i][cj],t[i-1][pj]),t[i][j]);
           t[i][j]++;
       }

    }
    cout<<endl<<t[e][f];
}

int main()
{


int f,e;
cin>>f>>e;
cout<<minimum_attempts(e,f);
by_tabulation(e,f);
    return 0;
}