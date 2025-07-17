class Solution {
public:
    bool check(vector<vector<char>>& board){
        
        int n = 9;
        int m = 9;

        for(int i = 0; i < n; i++){
            map<int, int> mpp;
            for(int j = 0; j < m; j++){
                mpp[board[i][j]]++;

                if(board[i][j]!='.' && mpp[board[i][j]]>1){
                    return false;
                }
            }
        }

        for(int i = 0; i < m; i++){
            map<int, int> mpp;
            for(int j = 0; j < n; j++){
                mpp[board[j][i]]++;

                if(board[j][i]!='.' && mpp[board[j][i]]>1){
                    return false;
                }
            }
        }

        for(int k = 0; k < 9; k+=3){
            for(int l = 0; l < 9; l+=3){
                map<int, int> mpp;
                for(int i = k; i < k+3; i++){
                    for(int j = l; j < l+3; j++){
                        mpp[board[i][j]]++;

                        if(board[i][j]!='.' && mpp[board[i][j]]>1){
                            // cout<<board[i][j]<<" "<<mpp[board[i][j]]<<endl;
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return check(board);
    }
};