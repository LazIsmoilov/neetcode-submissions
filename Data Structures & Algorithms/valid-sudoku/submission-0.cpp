class Solution {
public:
    bool checkRows(vector<vector<char>>& board) {
        for (int r = 0; r < 9; ++r) {
            unordered_set<char> seen;                // fresh set for each row
            for (int c = 0; c < 9; ++c) {
                char cell = board[r][c];
                if (cell == '.') continue;           // skip empty cells, otherwise two '.' would count as a repeat
                if (seen.contains(cell)) return false;
                seen.insert(cell);
            }
        }
        return true;
    }

    bool checkCols(vector<vector<char>>& board) {
        for (int c = 0; c < 9; ++c) {
            unordered_set<char> seen;                // fresh set for each column
            for (int r = 0; r < 9; ++r) {
                char cell = board[r][c];
                if (cell == '.') continue;
                if (seen.contains(cell)) return false;
                seen.insert(cell);
            }
        }
        return true;
    }

    bool checkBoxes(vector<vector<char>>& board) {
        vector<unordered_set<char>> boxes(9);        // one set per box, all alive at once
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char cell = board[r][c];
                if (cell == '.') continue;
                int box = (r / 3) * 3 + (c / 3);     // which box (0–8)
                if (boxes[box].contains(cell)) return false;
                boxes[box].insert(cell);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return checkRows(board) && checkCols(board) && checkBoxes(board);
    }
};
