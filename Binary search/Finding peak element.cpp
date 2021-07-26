#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//finding peak element in a array


/*
int peak(vector<int> a,int n)
{
int f=0,l=n-1,mid;
while(f<=l)
{
mid=(f+l)/2;
if(mid>0&&mid<n-1)
{if(a[mid]>a[mid-1]&&a[mid]>a[mid+1])
return a[mid];
}
else {if(mid==0)
if(a[mid+1]<a[mid])
return a[mid];
else if(mid==n-1)
if(a[mid-1]<a[mid])
return a[mid];
}
}
}
*/

int peak(vector<int> a, int n)
{
int f=0,l=n-1,mid;

while(f<=l)
{
mid=(f+l)/2;    
    
    
if(mid>0 && mid<n-1)
{if(a[mid]>a[mid+1]&&a[mid]>a[mid-1])
return mid;

else if(a[mid]<=a[mid+1])
f=mid+1;
else if(a[mid]<=a[mid-1])
l=mid-1;
}


else if(mid==0)
{
    if(a[mid+1]<a[mid])
    return mid;
    else return -1;
}
else if(mid==n-1)
{
    if(a[mid-1]<a[mid])
    return mid;
    else return -1;
}
}
}


int main()
{

int n;
cin>>n;
vector<int> a(n);
for(int i=0;i<n;i++)
cin>>a[i];

cout<<peak(a,n);


return 0;}