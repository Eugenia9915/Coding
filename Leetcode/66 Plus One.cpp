class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int div=0;
        digits[digits.size()-1]++;
        for(int i=digits.size()-1;i>=0;i--){
            digits[i]+=div;
            div = digits[i]/10;
            digits[i]%=10;
        }
        if(div!=0)digits.insert(digits.begin(),div);
        return digits;
    }
};