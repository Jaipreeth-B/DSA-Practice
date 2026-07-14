class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //create
        //validate presudoku board
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);
        //use hashing to map indices
        for(int i = 0 ; i < 9 ; i++)
        {
            for(int j = 0 ; j < 9 ; j++)
            {
                char val = board[i][j];
                if(val == '.') continue;//skip below blocks of code
                int boxIdx = (i/3)*3 + (j/3);
                //validate
                if(rows[i].count(val) || cols[j].count(val) || boxes[boxIdx].count(val))
                {
                    return false;
                }
                rows[i].insert(val);
                cols[j].insert(val);
                boxes[boxIdx].insert(val);
            }
        }
        return true;
    }
};