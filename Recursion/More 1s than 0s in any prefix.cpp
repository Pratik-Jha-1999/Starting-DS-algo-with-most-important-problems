#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void more_ones_than_zeros_in_prefix(int n,int o,int z,string s)
{

if(o+z==n)
{
    cout<<s<<endl;
    return ;
}

if(o!=n)
more_ones_than_zeros_in_prefix(n,o+1,z,s+"1 ");

if(o>z)
more_ones_than_zeros_in_prefix(n,o,z+1,s+"0 ");

}






int main()
{
int n;
cin>>n;

int o=0;
int z=0;

more_ones_than_zeros_in_prefix(n,o,z,"");


    return 0;
}