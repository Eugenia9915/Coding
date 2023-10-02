class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)return "";
        int min_len=strs[0].length(),index;
        for(int i=1;i<strs.size();++i){
            if(strs[i].length()<min_len){
                min_len=strs[i].length();
                index=i;
            }
        }
        string longest="";
        for(int j=0,i;j<min_len;++j){
            for(i=0;i<strs.size()-1;++i){
                if(strs[i][j]!=strs[i+1][j])return longest;
            }
            longest+=strs[i][j];
        }
        return longest;
    }
};