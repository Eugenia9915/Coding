class Solution {
public:
    int climbStairs(int n) {
        int s[46];
        s[1]=1;s[2]=2;
        for(int i=3;i<46;i++){
            s[i]=s[i-1]+s[i-2];
        }
        return s[n];
    }
};