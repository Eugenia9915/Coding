class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp, dp2;
        if(nums.size() == 1) return nums[0];
        dp.push_back(nums[0]);
        dp.push_back(max(nums[1],nums[0]));
        for(int i=2;i<nums.size()-1;i++){
            dp.push_back(max(dp[i-1],nums[i]+dp[i-2]));
        }
        dp2.push_back(0);
        dp2.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            dp2.push_back(max(dp2[i-1],nums[i]+dp2[i-2]));
        }
        return max(dp[dp.size()-1],dp2[dp2.size()-1]);
    }
};