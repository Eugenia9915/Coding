class Solution {
public:
    string longestPalindrome(string s) {
        // DP method here
        bool dp[1001][1001];
        int max_length = 0, start, last;
        
        for(int i=s.length()-1;i>=0;i--){
            for(int j=i;j<s.length();j++){
                if(i == j)dp[i][j] = true;
                else if(j-1 == i && s[i] == s[j]) dp[i][j] = true;
                else{
                    dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
                }
                if(dp[i][j] && (j-i+1)>max_length){
                    start = i;
                    last = j+1;
                    max_length = j-i+1;
                }
            }
        }
        return s.substr(start, max_length);
    }
};
