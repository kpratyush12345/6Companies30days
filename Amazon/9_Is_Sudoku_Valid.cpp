// https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1/

class Solution
{
public:
    int isValid(vector<vector<int>> board)
    {
        // code here
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};

        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[i].size(); ++j)
                if (board[i][j] != 0)
                {
                    int num = board[i][j] - 1, k = i / 3 * 3 + j / 3;
                    if (used1[i][num] || used2[j][num] || used3[k][num])
                        return 0;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
        return 1;
    }
};