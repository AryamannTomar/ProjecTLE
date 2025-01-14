#include<bits/stdc++.h>
using namespace std;

/*
P1 Block Sequence
Beautiful Sequence like 3_345_2_61
Find minimum number of deletions required to make the sequence beautiful

Same as retaining max no of elements 
511111____ (Better) In future can help
51_11__111

State
dp[i]: max no of elements we can retain from [i to n-1] in the array 
such that all new blocks will be formed from this range

Transition
dp[i]=max(dp[i+1+a[i]],dp[i+1])

Final Ans 
n-dp[0]
*/

void p1(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    for(int i=n-1;i>=0;i--){
        int pick=0;
        int a=1+arr[i];
        int b=i+1+arr[i];
        if(a<n){
            pick+=a;
            if(b<n) pick+=dp[b];
        }
        int skip=0;
        if(i+1<n) skip+=dp[i+1];
        dp[i]=max(skip,pick);
    }
    cout<<n-dp[0]<<endl;
}

/*
P2 Color with Occurrences
*/
void p2(){

}

/*
P3 Flowers
P4 Removal Game
*/

// ***************************************************************************************************************************************