class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1) return 0;
        int profit = 0, minn;
        for(int i=0;i<prices.size();i++){
            if(i>0){
                if(prices[i]>=minn) profit = max(profit, prices[i]-minn);
                else minn = prices[i];
            }
            else minn = prices[i];
        }
        return profit;
    }
};