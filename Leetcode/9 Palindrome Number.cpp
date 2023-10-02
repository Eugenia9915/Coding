class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        string t=to_string(x);
        for(int i=0,j=t.length()-1;i<j;i++,j--){
                if(t[i]!=t[j])return false;
        }
        return true;
    }
};