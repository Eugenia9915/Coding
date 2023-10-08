class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        sort(nums.begin(), nums.end());
        int n = nums.size(), cur, cnt;
        for(int i=0;i<nums.size();i++){
            if(i>0){
                if(nums[i] == cur){
                    cnt++;
                    if(cnt>(n/2)) return cur;
                }else{
                    cur = nums[i];
                    cnt = 1;
                }
            }else{
                cur = nums[i];
                cnt = 1;
            }
        }
        return -1;
    }
};