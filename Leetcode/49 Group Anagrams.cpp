class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<char,int> m;
        vector<unordered_map<char,int>> v;
        vector<string> s;
        vector<vector<string>> ans;
        bool found;
        for(int i=0;i<strs.size();i++){
            for(int j=0;j<strs[i].length();j++){
                if(m.find(strs[i][j]) == m.end())
                    m.insert(pair<char,int>(strs[i][j],1));
                else
                    m[strs[i][j]]++;
            }
            if(v.empty()){
                v.push_back(m);
                s.push_back(strs[i]);
                ans.push_back(s);
            }else{
                found = false;
                for(int j=0;j<v.size();j++){
                    if(m == v[j]){
                        ans[j].push_back(strs[i]);
                        found = true;
                        break;
                    }
                }
                if(!found){
                    v.push_back(m);
                    s.push_back(strs[i]);
                    ans.push_back(s);
                }
            }
            m.clear();
            s.clear();
        }
        return ans;
    }
};