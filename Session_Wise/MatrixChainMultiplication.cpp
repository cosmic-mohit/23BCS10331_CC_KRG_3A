class Solution {
  public:
    int mcm(vector<int> &arr,int i,int j,int n,vector<vector<int>> &dp){
        if(i>=j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        for(int k=i;k<j;k++){
            int tempAns = mcm(arr,i,k,n,dp)+mcm(arr,k+1,j,n,dp)+arr[i-1]*arr[k]*arr[j];
            ans=min(ans,tempAns);
        }
        dp[i][j] = ans;
        return ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return mcm(arr,1,n-1,n,dp);
    }
};