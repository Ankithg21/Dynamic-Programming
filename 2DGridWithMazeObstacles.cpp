//Given a ‘N’ * ’M’ maze with obstacles, count and return the number of unique paths 
// to reach the right-bottom cell from the top-left cell. A cell in the given maze has a 
// value '-1' if it is a blockage or dead-end, else 0. From a given cell, we are allowed 
// to move to cells (i+1, j) and (i, j+1) only. Since the answer can be large, print it 
// modulo 10^9 + 7.

#include<bits/stdc++.h>
using namespace std;
int mod=(int)(1e9 + 7);
//Recursion.
int f(int i,int j,vector<vector<int>> &mat){
    //base case.
    if(i==0 && j==0)return 1;
    if(i<0 || j<0)return 0;
    if(mat[i][j]==-1)return 0;
    int up=f(i-1,j,mat);
    int left=f(i,j-1,mat);
    return up+left;
}
//Memoization.
int f2(int i,int j,vector<vector<int>> &mat,vector<vector<int>> &dp){
    //base case.
    if(i==0 && j==0)return 1;
    if(i<0 || j<0)return 0;
    if(mat[i][j]==-1 && i>=0 && j>=0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int up=f2(i-1,j,mat,dp);
    int left=f2(i,j-1,mat,dp);
    return dp[i][j]=(up+left)%mod;
}
//Tabulation.
int f3(int n,int m,vector<vector<int>> &mat){
    int dp[n][m];
    for(int i=0;i<n;i=i+1){
        for(int j=0;j<m;j=j+1){
            if(i==0 && j==0)dp[i][j]=1;
            else if(mat[i][j]==-1)dp[i][j]=0;
            else{
                int up=0,left=0;
                if(i>0)up=dp[i-1][j];
                if(j>0)left=dp[i][j-1];
                dp[i][j]=(up+left)%mod;
            }
        }
    }
    return dp[n-1][m-1];
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here.
    return f3(n,m,mat);//OPTIMAL SOLUTION.
    // vector<vector<int>> dp(n,vector<int>(m,-1));
    // return f2(n-1,m-1,mat,dp);
}
int main(){
    return 0;
}