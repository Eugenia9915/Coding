class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> m;

        for(int i = 0;i<nums.size();i++){
            if(m.find(nums[i]) == m.end()){
                m.insert(pair<int,int>(nums[i],1));
            }
        }
        bool first = true;
        int prev, cnt, ans;
        for(pair<int,int> p:m){
            if(first){
                prev = p.first;
                ans = 1;
                cnt = 1;
                first = false;
            }
            else{
                if(prev + 1 == p.first){
                    cnt++;
                }
                else{
                    ans = max(ans, cnt);
                    cnt = 1;
                }
                prev = p.first;
            }
            
        }

        return max(ans, cnt);
    }
};