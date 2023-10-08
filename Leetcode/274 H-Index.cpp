class Solution {
public:
    int hIndex(vector<int>& citations) {
        int c[1001] = {0}, cnt = 0;
        for(int i=0;i<citations.size();i++) c[citations[i]]++;
        for(int i=1000;i>=0;i--){
            cnt += c[i];
            if(cnt >= i) return i;
        }
        return -1;
    }
};