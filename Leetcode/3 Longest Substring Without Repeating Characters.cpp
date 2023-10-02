class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> myset;
        int ans = 0;
        int t = 0;
        int start = 0;
        // cout<<s.length()<<endl;
        for(int i=0;i<s.length();i++){
            t++;
            myset.insert(s[i]);
            if(myset.size() < t){
                ans = max(ans, t-1);
                while(s[start] != s[i]){ 
                    myset.erase(s[start]);
                    start++;
                }
                t = i-start;
                start++;
            }else{
                ans = max(ans, t);
            }
            // cout<<start<<endl;
        }
        return ans;
    }
};