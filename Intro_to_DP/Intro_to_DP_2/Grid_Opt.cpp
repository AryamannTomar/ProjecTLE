#include <bits/stdc++.h>
using namespace std;

int x=0;
int helper(int i,int j,int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
    x++;
    if((i>m-1)||(j>n-1)) return INT_MAX;
    if((i==m-1)&(j==n-1)) return grid[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=grid[i][j]+min(helper(i+1,j,m,n,grid,dp),helper(i,j+1,m,n,grid,dp));
}

int x1=0;
int helper1(int i,int j,int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
    x1++;
    if((i<0)||(j<0)) return INT_MAX;
    if((i==0)&(j==0)) return grid[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=grid[i][j]+min(helper1(i-1,j,m,n,grid,dp),helper1(i,j-1,m,n,grid,dp));
}

int x2=0;
int helper2(int m, int n, vector<vector<int>>& grid){
    vector<vector<int>> dp2(m,vector<int>(n,INT_MAX));
    dp2[m-1][n-1]=grid[m-1][n-1];
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i<m-1) dp2[i][j]=min(dp2[i][j],grid[i][j]+dp2[i+1][j]);
            if(j<n-1) dp2[i][j]=min(dp2[i][j],grid[i][j]+dp2[i][j+1]);
            x2++;
        }
    }
    return dp2[0][0];
}

int main(){
    vector<vector<int>>grid={{1,2,3},{2,6,8},{3,5,1}};    
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    vector<vector<int>> dp1(m,vector<int>(n,-1));
    cout<<helper(0,0,m,n,grid,dp)<<" ";
    cout<<helper1(m-1,n-1,m,n,grid,dp1)<<" ";
    cout<<helper2(m,n,grid)<<endl;

    cout<<x<<endl<<x1<<endl<<x2;
    return 0;
}