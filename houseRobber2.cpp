//PROBLEM STATEMENT.
// Mr. X is a professional robber planning to rob houses along a street.
// Each house has a certain amount of money hidden.
// All houses along this street are arranged in a circle. 
// That means the first house is the neighbour of the last one. 
// Meanwhile, adjacent houses have a security system connected, 
// and it will automatically contact the police if two adjacent houses are broken into on 
// the same night.
// You are given an array/list of non-negative integers 'ARR' representing the amount of money 
// of each house. Your task is to return the maximum amount of money 
// Mr. X can rob tonight without alerting the police.

//LOGICAL PART REMAINS SAME AS MAXIMUM SUM OF NON ADJACENT ELEMENT.

#include<bits/stdc++.h>
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

    vector<int> temp1,temp2;
    for(int i=0;i<n;i=i+1){
        if(i!=0)temp1.push_back(nums[i]);
        if(i!=n-1)temp2.push_back(nums[i]);
    }

    vector<int> dp1(n,0);
    vector<int> dp2(n,0);

    int res1=f2(temp1,dp1);
    int res2=f2(temp2,dp2);
    cout<<max(res1,res2)<<endl;

    return 0;
}

