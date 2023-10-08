class Solution {
public:
    string reverseWords(string s) {
        int start = -1;
        vector<string> v;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' ' && start==-1){
                start = i;
            }else if(s[i]==' '){
                if(start!=-1){
                    v.push_back(s.substr(start, i-start));
                    start = -1;
                }
            }
            if(i==s.length()-1 && s[i]!=' '){
                v.push_back(s.substr(start, i-start+1));
            }
        }
        string ans = "";
        for(int i=0;i<v.size();i++){
            ans = v[i] + ans;
            if(i<v.size()-1) ans = " " + ans; 
        }
        return ans;
    }
};