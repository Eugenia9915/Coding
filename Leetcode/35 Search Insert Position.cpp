class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, mid = (left + right) / 2;
        cout<<left<<" "<<right<<" "<<mid<<endl;
        while(left < right){
            if(left == right){
                if(nums[mid] < target) return mid+1;
                else if(nums[mid] > target) return mid-1;
            }
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) right = mid - 1;
            else if(nums[mid] < target) left = mid + 1;
            
            mid = (left + right) / 2;
            cout<<left<<" "<<right<<" "<<mid<<endl;
        }
        // cout<<left<<" "<<right<<" "<<mid<<endl;
        return -1;
    }
};