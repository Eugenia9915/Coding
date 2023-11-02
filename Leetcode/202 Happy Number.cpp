class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> m;
        while(1){
            if(m.find(n) == m.end()){
                int ans = 0, num = n;
                while(num!=0){
                    ans += (num%10)*(num%10);
                    num /= 10;
                }
                if(ans == 1) return true;
                m.insert(pair<int,int>(n, ans));
                n = ans;
            }
            else return false;
        }
        return false;
    }
};