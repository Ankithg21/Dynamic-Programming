//PROBLEM STATEMENT.
//https://atcoder.jp/contests/dp/tasks/dp_b
#include<bits/stdc++.h>
using namespace std;

//Tabulation solution -- (OPTIMAL APPROACH).
int kJump(int n,int k,vector<int> &nums,vector<int> &dp){
    dp[0]=0;
    for(int i=1;i<n;i=i+1){
        int minStep=INT_MAX;
        for(int j=1;j<=k;j=j+1){
            int jump;
            if(i-j >= 0)jump=dp[i-j] + abs(nums[i]-nums[i-j]);
            minStep=min(minStep,jump);
        }
        dp[i]=minStep;
    }
    return dp[n-1];
}

//Brute Force solution.
int f(int idx,vector<int> &nums,int k){
    //base case.
    if(idx==0)return 0;
    int minStep=INT_MAX;

    for(int j=1;j<=k;j=j+1){
        int jump;
        if(idx-j >= 0)jump=f(idx-j,nums,k) + abs(nums[idx]-nums[idx-j]);
        minStep=min(minStep,jump);
    }
    return minStep;
}

int main(){
    int n;
    cout<<"Enter the size:";
    cin>>n;
    vector<int> nums;

    for(int i=0;i<n;i=i+1){
        int ele;
        cin>>ele;
        nums.push_back(ele);
    }

    vector<int> dp(n);

    int k;
    cout<<"Enter K steps:";
    cin>>k;

    int ans1=f(n-1,nums,k);
    int ans2=kJump(n,k,nums,dp);
    cout<<"Brute Force Approach: "<<ans1<<endl;
    cout<<"Optimal Approach: "<<ans2<<endl;

    return 0;
}