#include<iostream>
#include<vector>
using namespace std;

vector<int> rotate(vector<int> b, int n, int k)
{
    vector<int> a=b;
    int temp=0;
while(k--)
{temp=a[0];
for(int i=0;i<n-1;i++){
a[i]=a[i+1];
a[i+1]=temp;
}
}
return a;
}



int number_of_rotations(vector<int> a,int n)
{
int l=n-1,f=0,mid;
while(f<=l)
{
mid=(f+l)/2;

if(a[mid]>a[mid+1]&&a[mid]>a[mid-1])
return mid;

if(a[mid]>a[l])
f=mid+1;

else 
l=mid-1;
}
return -1;
}



int main()
{

int n,t;
cin>>n;
vector<int> a;
for(int i=0;i<n;i++)
{
    cin>>t;
    a.push_back(t);
};

int k;
cin>>k;
for(int i:a)
cout<<i<<" ";

a=rotate(a,n,k);

cout<<endl;
for(int i:a)
cout<<i<<" ";

int ans=number_of_rotations(a,n);
cout<<"This array is rotated "<<n-(ans+1)<<" times";


    return 0;
}