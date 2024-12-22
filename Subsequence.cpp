#include<bits/stdc++.h>
using namespace std;

void subsequence(int idx,int n,vector<int> &ds,vector<int> &nums){
    //base case.
    if(idx==n){
        for(int i=0;i<ds.size();i=i+1){
            cout<<ds[i]<<" ";
        }
        if(ds.size()==0){
            cout<<"{}"<<endl;
        }
        cout<<endl;
        return;
    }
    
    ds.push_back(nums[idx]);
    subsequence(idx+1,n,ds,nums);
    ds.pop_back();
    subsequence(idx+1,n,ds,nums);
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
    vector<int> ds;
    subsequence(0,n,ds,nums);
    return 0;
}