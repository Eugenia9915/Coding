class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map <long long,int> m;
        vector<int> tmp;
        vector<vector<int>> ans;
        int pos = 0, neg = 0;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i]) == m.end()){
                m.insert(pair<int,int>(nums[i], 1));
            }
            else{
                m[nums[i]]++;
            }
            if(nums[i]>0) pos++;
            if(nums[i]<0) neg++;
        }

        if(pos > 0 && neg == 0 && target < 0) return ans;
        else if(neg > 0 && pos == 0 && target > 0) return ans;

        for(pair<int,int> a : m){
            m[a.first]--;
            tmp.push_back(a.first);
            for(pair<int,int> b : m){
                if(b.first >= a.first && m[b.first] > 0){
                    m[b.first]--;
                    tmp.push_back(b.first);
                    for(pair<int,int> c : m){
                        if(c.first >= b.first && m[c.first] > 0){
                            m[c.first]--;
                            if(((long long)target-c.first-b.first-a.first)>=c.first 
                            && m.find((long long)target-c.first-b.first-a.first) != m.end() 
                            && m[(long long)target-c.first-b.first-a.first] > 0){
                                tmp.push_back(c.first);
                                tmp.push_back((long long)target-c.first-b.first-a.first);
                                ans.push_back(tmp);
                                tmp.pop_back();
                                tmp.pop_back();
                            }
                            m[c.first]++;
                        }
                    }
                    m[b.first]++;
                    tmp.pop_back();
                }
            }
            m[a.first]++;
            tmp.pop_back();
        }
        return ans;
    }
};