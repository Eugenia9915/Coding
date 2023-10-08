class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1)return 1;
        int cnt = 0, cur_num, cur_cnt;
        for(int i=0;i<nums.size();i++){
            if(i>0){
                if(nums[i] == cur_num){
                    if(cur_cnt < 2){
                        cur_cnt++;
                        cnt++;
                    }else{
                        nums.erase(nums.begin()+i);
                        i--;
                    }
                }else{
                    cur_num = nums[i];
                    cur_cnt = 1;
                    cnt++;
                }
            }else{
                cur_num = nums[i];
                cur_cnt = 1;
                cnt++;
            }
        }
        return cnt;
    }
};