class Solution {
public:
    int jump(vector<int>& nums) {
        int dp[10001];
        for(int i=0;i<10001;i++) dp[i]=-1;
        dp[0]=0;
        for(int i=0;i<nums.size();i++){
            if(dp[i]!=-1){
                int bnd = i+nums[i];
                for(int j=i+1;j<nums.size() && j <=bnd ;j++){
                    if(dp[j]==-1) dp[j]=i;
                }
            }
        }
        int index = nums.size()-1, cnt = 0;
        while(index!=0){
            cnt++;
            index = dp[index];
        }
        return cnt;
    }
};