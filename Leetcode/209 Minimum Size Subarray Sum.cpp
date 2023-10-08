class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start, sum = 0, min_s = 100000;
        bool found = false;
        for(int i=0;i<nums.size();i++){
            if(i>0){
                sum += nums[i];
                if(sum >= target){
                    while(sum-nums[start] >= target){
                        sum -= nums[start];
                        start ++;
                    }
                    min_s = min(min_s, i-start+1);
                    found = true;
                }
            }
            else{
                start = i;
                sum += nums[i];
                if(sum >= target){
                    min_s = min(min_s, i-start+1);
                    found = true;
                }
            }
        }
        if(found) return min_s;
        return 0;
    }
};