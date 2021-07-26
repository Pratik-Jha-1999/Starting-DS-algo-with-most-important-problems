#include<iostream>
#include<string.h>

using namespace std;
int t[21];

int stairpaths(int n)
{
if(t[n]!=-1)
return t[n];

if(n<=0)
return t[n]= 0;
if(n==1)
return t[n]=1;
if(n==2)
return t[n]= 2;
if(n==3)
return t[n]= 4;

int p1=stairpaths(n-1);
int p2=stairpaths(n-2);
int p3=stairpaths(n-3);

return t[n]=p1+p2+p3;
}


int main()
{
memset(t,-1,sizeof(t));

int n;
cin>>n;
cout<<stairpaths(n)<<endl;


    return 0;
}