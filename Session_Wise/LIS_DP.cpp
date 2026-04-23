class Solution {
public:
    // Recursive + Memoization
    int helper(int ind, int prevInd, vector<int>& nums,
               vector<vector<int>>& dp) {
        if (ind == nums.size()) {
            return 0;
        }
        if (dp[ind][prevInd + 1] != -1)
            return dp[ind][prevInd + 1];
        int notTake = helper(ind + 1, prevInd, nums, dp);
        int take = INT_MIN;
        if (prevInd == -1 || nums[ind] > nums[prevInd]) {
            take = 1 + helper(ind + 1, ind, nums, dp);
        }
        return dp[ind][prevInd + 1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        // Tabulation
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prevInd = ind - 1; prevInd >= -1; prevInd--) {
                int notTake = dp[ind + 1][prevInd + 1];
                int take = INT_MIN;
                if (prevInd == -1 || nums[ind] > nums[prevInd]) {
                    take = 1 + dp[ind + 1][ind + 1];
                }
                dp[ind][prevInd + 1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
};