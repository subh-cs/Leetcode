class Solution {
public:
    bool found(vector<vector<char>>& board, string word, int r, int c, int idx){
        if(idx==word.size()) return true;
        if(r<0 || r==board.size() || c<0 || c==board[0].size() || board[r][c]=='0' || word[idx] != board[r][c]) return false;
        
        char ch = board[r][c];
        board[r][c] = '0';
        
        bool bottom = found(board,word,r+1,c,idx+1);
        bool top = found(board,word,r-1,c,idx+1);
        bool right = found(board,word,r,c+1,idx+1);
        bool left = found(board,word,r,c-1,idx+1);
        
        board[r][c] = ch;
        return top || bottom || left || right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(found(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};