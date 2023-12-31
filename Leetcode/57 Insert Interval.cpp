class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        return (a[0] < b[0]);
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] <= ans[ans.size()-1][1] && intervals[i][0] >= ans[ans.size()-1][0] && intervals[i][1] >= ans[ans.size()-1][1])
                ans[ans.size()-1][1] = intervals[i][1];
            else if(intervals[i][0] >= ans[ans.size()-1][0] && intervals[i][1] <= ans[ans.size()-1][1]){}
            else if(intervals[i][1] >= ans[ans.size()-1][0] && intervals[i][1] <= ans[ans.size()-1][1])
                ans[ans.size()-1][0] = intervals[i][0];
            else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};