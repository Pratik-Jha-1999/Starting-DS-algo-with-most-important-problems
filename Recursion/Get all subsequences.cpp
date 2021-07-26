#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> getsubsequence(vector<int>in)
{
    if(in.size()==0)
    {
        vector<vector<int>> sop;
        return sop;
    }

   int t=in[in.size()-1];

   vector<int> sin;
   for(int i=0;i<in.size()-1;i++)
   sin.push_back(in[i]);

   vector<vector<int>> sop= getsubsequence(sin);
   int s=sop.size();
   if(s==0)
   {sop.resize(2);
   sop[1].push_back(t);
   } 
   
   else
   {for(int i=0;i<s;i++)
   {  
       sop.push_back(sop[i]);
      // sop[i].push_back(t);
   }   
   s=sop.size();
   for(int i=s/2;i<s;i++)
   sop[i].push_back(t);
   }
   
   
return sop;
}




int main()
{
   vector<int> in;
   int n,temp;
   cin>>n;
   for(int i=0;i<n;i++)
   {
     cin>>temp;
     in.push_back(temp);
   }
vector<vector<int>> ans=getsubsequence(in);
for(int i=0;i<ans.size();i++)
{for(int j=0;j<ans[i].size();j++)
cout<<ans[i][j]<<" ";
cout<<endl;
}
    return 0;
}