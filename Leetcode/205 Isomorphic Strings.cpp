class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,char> m, n;
        for(int i=0;i<s.length();i++){
            if(m.find(s[i])==m.end() && n.find(t[i])==n.end()){
                m.insert(pair<char,char>(s[i],t[i]));
                n.insert(pair<char,char>(t[i],s[i]));
            }
            else if(m[s[i]]!=t[i] || n[t[i]]!=s[i]) return false;
        }
        return true;
    }
};