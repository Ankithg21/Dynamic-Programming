//PROBLEM STATEMENT.
// There is a frog on the '1st' step of an 'N' stairs long staircase. 
// The frog wants to reach the 'Nth' stair. 'HEIGHT[i]' is the height of the '(i+1)th' stair.
// If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ). 
// If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair. 
// Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.

#include<bits/stdc++.h>
using namespace std;

//Tabulation solution - bottomUp approach (OPTIMAL APPROACH).
int jump3(int n,vector<int> &nums,vector<int> &dp){
    dp[0]=0;
    for(int i=1;i<n;i=i+1){
        int left=dp[i-1]+abs(nums[i]-nums[i-1]);
        int right=INT_MAX;
        if(i>=2)right=dp[i-2]+abs(nums[i]-nums[i-2]);
        dp[i]=min(left,right);
    }
    return dp[n-1];
}

//Momoization solution - topDown approach.
int jump2(int idx,vector<int> &nums,vector<int> &dp){
    //base case.
    if(idx==0)return 0;
    if(dp[idx] != -1)return dp[idx];
    int left=jump2(idx-1,nums,dp) + abs(nums[idx]-nums[idx-1]); 
    int right=INT_MAX;
    if(idx>=2)right=jump2(idx-2,nums,dp) + abs(nums[idx]+nums[idx-2]);
    return dp[idx]=min(left,right);
}

//brute force solution--Recursion concept.
int jump1(int idx,vector<int> &nums){
    //base case.
    if(idx==0)return 0;
    int left=jump1(idx-1,nums) + abs(nums[idx]-nums[idx-1]); 
    int right=INT_MAX;
    if(idx>=2)right=jump1(idx-2,nums) + abs(nums[idx]+nums[idx-2]);
    return min(left,right);
}

int main(){
    int n;
    cout<<"Enter the Size:";
    cin>>n;
    vector<int> nums;

    for(int i=0;i<n;i=i+1){
        int ele;
        cin>>ele;
        nums.push_back(ele);
    }

    vector<int> dp1(n,-1);
    vector<int> dp2(n,0);

    int ans1=jump1(n-1,nums);
    int ans2=jump2(n-1,nums,dp1);
    int ans3=jump3(n,nums,dp2);

    cout<<"Brute Force solution:"<<ans1<<endl;
    cout<<"better solution:"<<ans2<<endl;
    cout<<"optimal solution:"<<ans3<<endl;
    return 0;
}