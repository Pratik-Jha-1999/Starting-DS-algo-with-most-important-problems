#include <iostream>
#include<string.h>
using namespace std;
int t[46];
int fib(int n){
    if(t[n]!=-1)
    return t[n];
  
if(n<=2)
return t[n]=1;

return t[n]=fib(n-1)+fib(n-2);
}

int main(){
    memset(t,-1,sizeof(t));
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}