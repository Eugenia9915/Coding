class Solution {
public:
    void search(vector<vector<char>>& grid, int r, int c){
        if(r<grid.size() && c<grid[0].size() && r>=0 && c>=0 && grid[r][c] == '1'){
            grid[r][c] = '2';
            search(grid,r+1,c);
            search(grid,r-1,c);
            search(grid,r,c+1);
            search(grid,r,c-1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == '1'){
                    ans++;
                    search(grid,i,j);
                }
            }
        }
        return ans;
    }
};