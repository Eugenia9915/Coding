class Solution {
public:
    string convert(string s, int numRows) {
        int n = numRows == 1 ? 1 : 2*(numRows-1);
        int l = n, r = 0;
        string ans = "";
        for(int i=0;i<numRows && i<s.length();i++){
            int j=i;
            // cout<<s[j];
            ans += s[j];
            while(j < s.length()){
                if(l>0){
                    j+=l;
                    if(j<s.length()){
                        // cout<<s[j];
                        ans += s[j];
                    }
                }
                if(r>0){
                    j+=r;
                    if(j<s.length()){
                        // cout<<s[j];
                        ans += s[j];
                    }
                }
            }
            // cout<<l<<" "<<r<<endl;
            // cout<<ans<<endl;
            l-=2;r+=2;
        }
        return ans;
    }
};