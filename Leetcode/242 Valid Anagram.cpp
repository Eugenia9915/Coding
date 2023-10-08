class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> m, n;
        for(int i=0;i<s.length();i++){
            if(n.find(s[i]) == n.end()){
                if(m.find(s[i]) == m.end())
                    m.insert(pair<char,int>(s[i],1));
                else
                    m[s[i]]++;
            }
            else if(n[s[i]] > 1)
                n[s[i]]--;
            else
                n.erase(s[i]);
            if(m.find(t[i]) == m.end()){
                if(n.find(t[i]) == n.end())
                    n.insert(pair<char,int>(t[i],1));
                else
                    n[t[i]]++;
            }
            else if(m[t[i]] > 1)
                m[t[i]]--;
            else
                m.erase(t[i]);
        }
        if(m.empty() && n.empty()) return true;
        return false;
    }
};