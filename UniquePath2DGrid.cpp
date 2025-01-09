// You are present at point ‘A’ which is the top-left cell of an M X N matrix, 
// your destination is point ‘B’, which is the bottom-right cell of the same matrix. 
// Your task is to find the total number of unique paths from point ‘A’ to point ‘B’.
// In other words, you will be given the dimensions of the matrix as integers ‘M’ and ‘N’, 
// your task is to find the total number of unique paths from the cell MATRIX[0][0] to 
// MATRIX['M' - 1]['N' - 1].
// To traverse in the matrix, you can either move Right or Down at each step. 
// For example in a given point MATRIX[i] [j], you can move to either MATRIX[i + 1][j] or 
// MATRIX[i][j + 1].
#include<bits/stdc++.h> 
using namespace std;
//recursion
int f(int i,int j){
	//base case.
	if(i==0 && j==0)return 1;
	if(i<0 || j<0)return 0;
	int up=f(i-1,j);
	int left=f(i,j-1);
	return up+left;
}
//Memoization
int f2(int i,int j,vector<vector<int>> &dp){
	if(i==0 && j==0)return 1;
	if(i<0 || j<0)return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	int up=f2(i-1,j,dp);
	int left=f2(i,j-1,dp);
	return dp[i][j]=up+left;
}
//Tabulation.
int f3(int r,int c,vector<vector<int>> &dp){
	for(int i=0;i<r;i=i+1){
		for(int j=0;j<c;j=j+1){
			if(i==0 && j==0)dp[i][j]=1;
			else{
				int up=0,left=0;
				if(i>0)up=dp[i-1][j];
				if(j>0)left=dp[i][j-1];
				dp[i][j]=up+left;
			}
		}
	}
	return dp[r-1][c-1];
}
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(m,vector<int>(n,-1));
	vector<vector<int>> dp2(m+1,vector<int>(n+1,0));
	return f3(m,n,dp2);
}

int main(){
    int res= uniquePaths(3,3);
    cout<<res<<endl;
    return 0;
}