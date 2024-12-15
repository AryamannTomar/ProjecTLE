#include <bits/stdc++.h>
using namespace std;

int fnEntered=0;
int helper(int n){
    fnEntered++;
    if(n==1 || n==2) return 1;
    return helper(n-1)+helper(n-2);
}

int dp[42];
int fn2Entered=0;
int helper2(int n){
    fn2Entered++;
    if(n==1 || n==2) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=helper2(n-1)+helper2(n-2);
}

int main(){
    int n=40;
    for(int i=0;i<=40;i++) dp[i]=-1;
    cout<<helper(n)<<" "<<helper2(n)<<endl;
    cout<<"For n="<<n<<" fnEntered :- "<<fnEntered<<endl;
    cout<<"For n="<<n<<" fn2Entered :- "<<fn2Entered;
    return 0;
}