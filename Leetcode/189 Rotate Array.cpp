class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k==0 || nums.size()==1) return;
        k %= nums.size();
        vector<int> t;
        t.insert(t.begin(),nums.begin()+(nums.size()-k), nums.end());
        nums.erase(nums.begin()+(nums.size()-k), nums.end());
        nums.insert(nums.begin(),t.begin(),t.end());
    }
};