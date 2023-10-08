class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool valid[10], valid2[10];
        // row and col valid
        for(int i=0;i<9;i++){
            clear(valid);
            clear(valid2);
            for(int j=0;j<9;j++){
                if(board[i][j] >= '1' && board[i][j] <= '9'){
                    if(!valid[board[i][j]-'0'])
                        valid[board[i][j]-'0'] = true;
                    else
                        return false;
                }
                if(board[j][i] >= '1' && board[j][i] <= '9'){
                    if(!valid2[board[j][i]-'0'])
                        valid2[board[j][i]-'0'] = true;
                    else
                        return false;
                }
            }
        }
        // 3x3 valid
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                clear(valid);
                for(int k=0;k<9;k++){
                    if(board[i+k/3][j+k%3] >= '1' && board[i+k/3][j+k%3] <= '9'){
                        if(!valid[board[i+k/3][j+k%3]-'0'])
                            valid[board[i+k/3][j+k%3]-'0'] = true;
                        else
                            return false;
                    }
                }
            }
        }
        return true;
    }
    void clear(bool valid[10]){
        for(int i=0;i<10;i++) valid[i]=false;
    }
};