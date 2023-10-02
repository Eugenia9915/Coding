class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.length()-1,cnt=0;
        for(;i>=0;i--){
            if(s[i]!=' '){
                i--;
                cnt++;
                while(i>=0 && s[i]!=' '){
                    cnt++;
                    i--;
                }
                break;
            }
        }
        return cnt;
    }
};