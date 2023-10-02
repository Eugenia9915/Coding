class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp;
        if(nums.size() == 1) return nums[0];
        dp.push_back(nums[0]);
        dp.push_back(max(nums[1],nums[0]));
        for(int i=2;i<nums.size();i++){
            dp.push_back(dp[i-1]);
            dp[i] = max(dp[i],nums[i]+dp[i-2]);
        }
        return dp[nums.size()-1];
    }
};