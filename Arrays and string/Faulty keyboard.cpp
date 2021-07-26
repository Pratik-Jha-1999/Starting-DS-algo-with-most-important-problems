#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool if_keyfault(string s1, string s2)
{   
    if(s1.size()>s2.size())
     return false;

    int i=0,j=0;
    while(i<s1.size()&&j<s2.size())
    {
        if(s1[i]==s2[j])
        {
         i++;j++;
        }
        else 
        if(i>0&&s1[i-1]==s2[j])
        j++;
       else return false;
    }
if(i<s1.size())
return false;
else 
while(j<s2.size())
{
    if(s1[i-1]!=s2[j])
    return false;
    j++;
}
return true;
}

int main()
{
string s1,s2;
cin>>s1>>s2;
if(if_keyfault(s1,s2))
cout<<"faulty keyboard";
else cout<<"nopes";
cout<<endl;
    return 0;
}