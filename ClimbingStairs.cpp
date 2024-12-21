// You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair.
// Each time, you can climb either one step or two steps.
// You are supposed to return the number of distinct ways you can climb from the 0th step to the Nth step.

#include<bits/stdc++.h>
using namespace std;

int climbingStairs(int idx,vector<int> &nums){
    //base case.
    if(idx == 0)return 1;
    if(idx<0)return 0;
    int one=climbingStairs(idx-1,nums);
    int Two=climbingStairs(idx-2,nums);
    return one+Two;
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

    int ans=climbingStairs(n-1,nums);
    cout<<"Total Possible ways: "<<ans<<endl;
    return 0;
}