class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        bool find;
        int i,j;
        vector<int> ans;
        for(i=0;i<nums.size();i++){
            find=false;
            for(j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    find=true;
                    break;
                }
            }
            if(find){
                ans.push_back(i);
                ans.push_back(j);
            }
        }
        return ans;
    }
};