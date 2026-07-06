class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> frequencyRow;
        unordered_map<char, int> frequencyCol;
        unordered_map<char, int> frequencyBox[9];
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                //store as unordered map frequency table for 1-9 and dots "."
                frequencyRow[board[i][j]]++;   
                frequencyCol[board[j][i]]++;
                if((frequencyRow[board[i][j]] > 1 && (board[i][j] != '.')) || ((frequencyCol[board[j][i]] > 1) && (board[j][i] != '.'))) return false;

                //gets index of the box (kinda like blocks in cuda with threads)
                int boxIndex = (i/3) * 3 + (j/3);
                //increment the 1-9 or "." count for frequencyBox[boxIndex] depending on board[i][j]
                frequencyBox[boxIndex][board[i][j]]++;
                if((frequencyBox[boxIndex][board[i][j]] > 1) && (board[i][j] != '.')) return false;
            }
            frequencyRow.clear();
            frequencyCol.clear();
        }
        return true;
    }
};
