class Solution {
public:
    int myAtoi(string s) {
        bool start_int = false;
        int pos=0, neg=0;
        long long num = 0, max_v = pow(2, 31);
        for(int i=0;i<s.length();i++){
            if(!start_int && s[i] == ' '){}
            else if(s[i] == '-'){
                neg++;
                start_int = true;
            }
            else if(s[i] == '+'){
                pos++;
                start_int = true;
            }
            else if(s[i] >= '0' && s[i]<='9'){
                num *= 10;
                num += s[i]-'0';
                start_int = true;
                if(!((neg==0 && pos==0) || (neg==1 && pos==0) || (neg==0 && pos==1))) return 0;
                else if(neg>pos && num>max_v) return -1*max_v;
                else if(!(neg>pos) && num>(max_v-1)) return max_v-1;
                if(!(s[i+1] >= '0' && s[i+1]<='9')) break;
            }
            else if(s[i] == '.') break;
            else if(start_int && !(s[i] >= '0' && s[i]<='9')) return 0;
            else return 0;
        }
        return neg>pos?-1*num:num;
    }
};