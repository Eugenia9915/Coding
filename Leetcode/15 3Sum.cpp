class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                if(m[nums[i]]<3)m[nums[i]]++;
            }
            else m.insert(pair<int,int>(nums[i],1));
        }

        for(pair<int,int> n : m){
            m[n.first]--;
            for(pair<int,int> k : m){
                if(k.first>=n.first && m[k.first]>0){
                    m[k.first]--;
                    if((0-n.first-k.first)>=k.first && m.find(0-n.first-k.first) != m.end() && m[0-n.first-k.first]>0){
                        tmp.push_back(n.first);
                        tmp.push_back(k.first);
                        tmp.push_back(0-n.first-k.first);
                        ans.push_back(tmp);
                        tmp.pop_back();
                        tmp.pop_back();
                        tmp.pop_back();
                    }
                    m[k.first]++;
                }
            }
            m[n.first]++;
        }

        return ans;
    }
};