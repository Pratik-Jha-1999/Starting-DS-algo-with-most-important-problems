#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void balancedparanthesis(int n, int o, int c, string s)
{
    if(o==0&&c==0)
    {cout<<s<<endl;
    return;}

    if(o!=0)
        balancedparanthesis(n,o-1, c, s+"(");
    if(c>o)
    balancedparanthesis(n,o,c-1,s+")");

}




int main()
{
    int n;
    cin>>n;

    int o=n;
    int c=n;
    
    balancedparanthesis(n,o,c,"");







    return 0;
}