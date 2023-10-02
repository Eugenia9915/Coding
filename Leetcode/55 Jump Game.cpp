class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool dp[10001];
        for(int i=0;i<10001;i++) dp[i]=false;
        dp[0]=true;
        for(int i=0;i<nums.size();i++){
            if(dp[i]==true){
                int bnd = i+nums[i];
                for(int j=i+1;j<=bnd && j<nums.size();j++){
                    dp[j]=true;
                }
            }
        }
        return dp[nums.size()-1];
    }
};