#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; ++i)
        {
            if (false == isValidRow(board, i))
            {
                return false;
            }

            if (false == isValidCol(board, i))
            {
                return false;
            }
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (false == isValidCube(board, i, j)) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    bool isValidRow(vector<vector<char>>& board, int row){
        unordered_set<char> seen;

        for (int i = 0; i < 9; ++i) {
            char val = board[row][i];

            if ('.' != val) {
                if (seen.find(val) != seen.end()) {
                    return false;
                }

                seen.insert(val);
            }
        }

        return true;
    }

    bool isValidCol(vector<vector<char>>& board, int col){
        unordered_set<char> seen;

        for (int i = 0; i < 9; ++i){
            char val  = board[i][col];

            if ('.' != val){
                if (seen.find(val) != seen.end()){
                    return false;
                }

                seen.insert(val);
            }
        }

        return true;
    }

    bool isValidCube(vector<vector<char>>& board, int row, int col){
        unordered_set<char> seen;

        for (int i = row; i < row + 3; ++i) {
            for (int j = col; j < col + 3; ++j) {
                char val = board[i][j];

                if ('.' != val) {
                    if (seen.find(val) != seen.end()) {
                        return false;
                    }

                    seen.insert(val);
                }
            }
        }

        return true;
    }
};

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution sol;
    bool isValid = sol.isValidSudoku(board);

    if (isValid) {
        cout << "The Sudoku board is valid." << endl;
    } else {
        cout << "The Sudoku board is not valid." << endl;
    }

    return 0;
}