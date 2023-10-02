class Solution {
public:
    int strStr(string haystack, string needle) {
        bool exist;
        if(needle.length()==0) return 0;
        else{
            int i=0,j=0,index=-1;
            for(;i+needle.length()<=haystack.length();i++){
                exist = false;
                if(haystack[i]==needle[j]){ //compare the rest needle
                    exist = true;
                    index=i;
                    int k=i;
                    for(;j<needle.length();j++,k++){
                        if(haystack[k]!=needle[j]){
                            exist = false;
                            j=0;
                            break;
                        }
                    }
                }
                if(exist) break;
            }
            if(exist) return index;
            else return -1;
        }
    }
};