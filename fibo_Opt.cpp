#include <bits/stdc++.h>
using namespace std;

int x=0;
int fibo(int i){
    x++;
    if((i==0)||(i==1)) return i;
    return fibo(i-1)+fibo(i-2);
}

int x1=0;
vector<int> dp(100,-1);
int fibo1(int i){
    x1++;
    if((i==0)||(i==1)) return i;
    if(dp[i]!=-1) return dp[i];
    return dp[i]=fibo1(i-1)+fibo1(i-2);
}

int x2=0;
vector<int> dp2(100,-1);
int fibo2(int i){
    dp2[1]=0;
    dp2[2]=1;
    for(int j=3;j<=i+1;j++){
        x2++;
        dp2[j]=dp2[j-1]+dp2[j-2];
    };
    return dp2[i+1];
}

int main(){
    cout<<fibo(40)<<" ";
    cout<<fibo1(40)<<" ";
    cout<<fibo2(40)<<endl;
    cout<<x<<endl;
    cout<<x1<<endl;
    cout<<x2<<endl;
    return 0;
}