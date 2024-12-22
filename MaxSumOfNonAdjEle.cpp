#include <bits/stdc++.h> 
using namespace std;
//Tabulation -- OPTIMAL APPRAOCH.
int f2(vector<int> &nums,vector<int> &dp){
    dp[0]=nums[0];
    for(int i=1;i<nums.size();i=i+1){
        int pick=nums[i];
        if(i>1)pick+=dp[i-2];
        int notpick=0 + dp[i-1];
        dp[i]=max(pick,notpick);
    }
    return dp[nums.size()-1];
}

//Memoization -- Better solution.
int f(int idx,vector<int> &nums,vector<int> &dp){
    //base case.
    if(idx==0)return nums[idx];
    if(dp[idx]!=-1)return dp[idx];
    if(idx < 0)return 0;
    int pick=nums[idx] + f(idx-2,nums,dp);
    int notpick=0 + f(idx-1,nums,dp);
    return dp[idx]=max(pick,notpick);
}

//Brute Force solution.
int brute(int idx,vector<int> &nums){
    //base case.
    if(idx==0)return nums[idx];
    if(idx<0)return 0;
    int pick=nums[idx]+brute(idx-2,nums);
    int notpick=0+brute(idx-1,nums);
    return max(pick,notpick);
}

int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i=i+1){
        int ele;
        cin>>ele;
        nums.push_back(ele);
    }
    vector<int> dp(n,-1);
    vector<int> dp2(n+1,0);
    // return brute(n-1,nums); //brute force call
    // return f(n-1,nums,dp);  // better Call.
    cout<<f2(nums,dp)<<endl;


    return 0;
}