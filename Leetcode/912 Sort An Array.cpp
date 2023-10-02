class Solution {
public:
    void mergeSort(int left, int right, vector<int>& nums){
        int mid = (left + right)/2;
        if(left < right){
            mergeSort(left, mid, nums);
            mergeSort(mid+1, right, nums);
            merge(left, right, nums);
        }
    }
    void merge(int left, int right, vector<int>& nums){
        int mid = (left + right)/2;
        int k = 0;
        int t[right-left+1];
        for(int i=left, j=mid+1; i<=mid || j<=right;){
            if(i>mid) t[k++] = nums[j++];
            else if(j>right) t[k++] = nums[i++];
            else if(nums[i] < nums[j]) t[k++] = nums[i++];
            else t[k++] = nums[j++];
        }
        k = 0;
        for(int i=left;i<=right;i++){
            nums[i] = t[k++];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0, nums.size()-1, nums);
        return nums;
    }
};