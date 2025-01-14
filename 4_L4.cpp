#include<bits/stdc++.h>
using namespace std;

/*
1 Book Shop [KnapSack Problem]
Find out which subset of books has a total Price<=X and total no. of pages is maximised

Stater
*/

int solve(){
    int n,x;
    cin>>n>>x;
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    vector<int> price(n), pages(n);
    for(auto &p: price) cin>>p;
    for(auto &p: pages) cin>>p;

    for(int i=n-1;i>=0;i--){
        for(int b=0;b<=x;b++){
            int pick=0,skip=0;
            if(b>=price[i]) pick=pages[i]+dp[i+1][b-price[i]];
            skip=dp[i+1][b];
            dp[i][b]=max(pick,skip);
        }
    }
    cout<<dp[0][x]<<endl;
}

// ***************************************************************************************************************************************