class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // n:row, m:col
        int n = matrix.size(), m = matrix[0].size();
        int up_bor = 0, right_bor = 0, left_bor = 0, down_bor = 0;
        bool up = false, right = true, left = false, down = false;
        vector<int> ans;
        int i=0, j=0, prev_i=-1, prev_j=-1;
        while(up_bor+down_bor<n || left_bor+right_bor<m){
            if(prev_i!=i || prev_j!=j){
                ans.push_back(matrix[i][j]);
                prev_i = i;
                prev_j = j;
            }
            if(right){
                if(up_bor+down_bor==n-1) left_bor++;
                if(j+1<m-right_bor) j++;
                else{
                    right = false;
                    down = true;
                    up_bor++;
                }
            }
            else if(left){
                if(up_bor+down_bor==n-1) right_bor++;
                if(j-1>=left_bor) j--;
                else{
                    left = false;
                    up = true;
                    down_bor++;
                }
            }
            else if(down){
                if(left_bor+right_bor==m-1) up_bor++;
                if(i+1<n-down_bor) i++;
                else{
                    down = false;
                    left = true;
                    right_bor++;
                }
            }
            else if(up){
                if(left_bor+right_bor==m-1) down_bor++;
                if(i-1>=up_bor)i--;
                else{
                    up = false;
                    right = true;
                    left_bor++;
                }
            }
        }
        return ans;
    }
};