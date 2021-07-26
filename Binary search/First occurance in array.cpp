#include<iostream>

using namespace std;


void first_occurance(int a[],int n, int k)
{
    int f=0,l=n-1;
    int mid;
while(f<=l)
{mid=(f+l)/2;

  if(a[mid]==k&&a[mid-1]!=k)
  break;
else if(a[mid]==k||a[mid]>k)
l=mid-1;

else if(mid<=k)
f=mid+1;
}
if(f<=l)
cout<<mid;
else cout<<" not found ";

}

int main()
{
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];
int k;
cin>>k;
first_occurance(a,n,k);

    return 0;
}