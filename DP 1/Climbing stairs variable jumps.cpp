#include <iostream>
#include<string.h>
using namespace std;
int t[21];//take this size according to question

int variable_stairs(int arr[], int n){
t[n]=1;

for(int i=n-1;i>=0;i--)
for(int j=1;j<=arr[i]&&(i+j)<n+1;j++)
t[i]+=t[i+j];

return t[1];

    return 0;
}

int main(){
    int n;
    cin>>n;
    memset(t,0,sizeof(t));
    
    int arr[n];
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    cout<<variable_stairs(arr,n)<<endl;
}