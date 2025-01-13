#include <bits/stdc++.h>
using namespace std;

/*
1 FIBO
*/
int dp[42];
int fibo(int n){
    if(n==1 || n==2) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=fibo(n-1)+fibo(n-2);
}

/*
2 GRID Prob
*/
int helper(int i,int j,int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
    if((i>m-1)||(j>n-1)) return INT_MAX;
    if((i==m-1)&(j==n-1)) return grid[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=grid[i][j]+min(helper(i+1,j,m,n,grid,dp),helper(i,j+1,m,n,grid,dp));
}

/*
3 Max Adjacent Sum
*/

int main(){
    int n=40;
    for(int i=0;i<=40;i++) dp[i]=-1;
    cout<<fibo(n)<<endl;
    return 0;
}