class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, tmp = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>=prices[i-1]) tmp += (prices[i]-prices[i-1]);
            else{
                profit += tmp;
                tmp = 0;
            }
        }
        profit += tmp;
        return profit;
    }
};