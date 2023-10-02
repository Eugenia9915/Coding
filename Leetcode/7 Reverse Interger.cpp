class Solution {
public:
    int reverse(int x) {
        long long num = 0;
        bool minus;
        if(x<0) minus = true;
        else minus = false;
        x=abs(x);
        while(x>0){
            if(num*10 > pow(2, 31)) return 0;
            else num*=10;
            num += x%10;
            x/=10;
        }
        if(minus) num*=-1;
        return num; 
    }
};