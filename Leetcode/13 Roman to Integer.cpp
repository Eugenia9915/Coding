class Solution {
public:
    int romanToInt(string s) {
        int cnt = 0;
        for(int i=0;i<s.length();i++){
            // cout<<s[i]<<endl;
            switch(s[i]){
                case 'I':
                    cnt += 1;
                    break;
                case 'V':
                    if(i>0 && s[i-1] == 'I') cnt-=2;
                    cnt += 5;
                    break;
                case 'X':
                    if(i>0 && s[i-1] == 'I') cnt-=2;
                    cnt += 10;
                    break;
                case 'L':
                    if(i>0 && s[i-1] == 'X') cnt-=20;
                    cnt += 50;
                    break;
                case 'C':
                    if(i>0 && s[i-1] == 'X') cnt-=20;
                    cnt += 100;
                    break;
                case 'D':
                    if(i>0 && s[i-1] == 'C') cnt-=200;
                    cnt += 500;
                    break;
                case 'M':
                    if(i>0 && s[i-1] == 'C') cnt-=200;
                    cnt += 1000;
                    break;
            }
        }
        return cnt;
    }
};