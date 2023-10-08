class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m;
        unordered_map<string, char> n;
        vector<string> ss;
        int last;
        while(s.find(" ")!=-1){
            last = s.find(" ");
            ss.push_back(s.substr(0,last));
            s = s.substr(last+1);
        }
        ss.push_back(s);

        if(pattern.length()!=ss.size()) return false;
        for(int i=0;i<pattern.length();i++){
            if(m.find(pattern[i])==m.end() && n.find(ss[i])==n.end()){
                m.insert(pair<char,string>(pattern[i],ss[i]));
                n.insert(pair<string,char>(ss[i],pattern[i]));
            }
            else if(m[pattern[i]]!=ss[i] || n[ss[i]]!=pattern[i])
                return false;
        }
        return true;
    }
};

