#include<bits/stdc++.h>

int bruh(int i,int j,vector<int>&v,vector<vector<int>> &dp){
    int ans=1e9;
    if(dp[i][j]!=-1)return dp[i][j];
    for(int k=i+1;k<j;k++){
        int p=v[j]-v[i]+bruh(i,k,v,dp)+bruh(k,j,v,dp);
        ans=min(ans,p);
    }
    if(ans==1e9)return dp[i][j]=0;
    return dp[i][j]=ans;
}
int cost(int n, int c, vector<int> &d){
    
    vector<int>v;v.push_back(0);
    {
        sort(d.begin(),d.end());
        for(auto &i:d)v.push_back(i);
        v.push_back(n);c+=2;
    }
    vector<vector<int>>dp(c,vector<int>(c,0));
//     return bruh(0,c-1,v,dp); 
    
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<c;j++){
               int ans=1e9;
               for(int k=i+1;k<j;k++){
               int p=v[j]-v[i]+dp[i][k]+dp[k][j];
               ans=min(ans,p);
                }
            if(ans==1e9)continue;
            dp[i][j]=ans;  
        }
    }
    
    return dp[0][c-1];
    
}
