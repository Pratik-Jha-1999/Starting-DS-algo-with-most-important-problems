#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;


bool ispalindrome(string s,int i,int j)
{
   int f=0;

   do{
       if(s[i]!=s[j])
       f=1;
       i++;
       j--;

   }while(i<=j);
   
   if(f==0)
   return true;
   else 
   return false;
}

int minimum_partitions(string s ,int i,int j)
{
 if(i>=j)
 return 0;

 if(ispalindrome(s,i,j))
 return 0;

 int minp=INT_MAX;

 for(int k=i;k<j;k++)
 {
  minp=min(minp,minimum_partitions(s,i,k)+minimum_partitions(s,k+1,j)+1);
 }


return minp;

}




int main()
{
string s;
cin>>s;

cout<<minimum_partitions(s,0,s.length()-1);

    return 0;
}