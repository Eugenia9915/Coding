class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int start, end;
        vector<string> ans;
        if(nums.size()==0) return ans;
        for(int i=0;i<nums.size();i++){
            if(i>0){
                if(nums[i] == nums[i-1]+1)
                    end = nums[i];
                else{
                    if(start == end)
                        ans.push_back(to_string(start));
                    else
                        ans.push_back(to_string(start)+"->"+to_string(end));
                    start = nums[i];
                    end = nums[i];
                }
            }else{
                start = nums[i];
                end = nums[i];
            }
        }
        if(start == end)
            ans.push_back(to_string(start));
        else
            ans.push_back(to_string(start)+"->"+to_string(end));
        return ans;
    }
};