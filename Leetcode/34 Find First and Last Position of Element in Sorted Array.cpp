class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, mid;
        bool found = false;
        while(left<=right){
            mid = (left + right)/2;
            if(nums[mid] == target){
                found = true;
                break;
            }
            else if(nums[mid] > target){
                right = mid-1;
            }
            else{
                left = mid + 1;
            }
        }
        vector<int> ans;
        if(found){
            left = mid;
            right = mid;
            while(left-1 >=0 && nums[left-1] == target) left--;
            while(right+1 < nums.size() && nums[right+1] == target) right++;
            ans.push_back(left);
            ans.push_back(right);
        }
        else{
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};