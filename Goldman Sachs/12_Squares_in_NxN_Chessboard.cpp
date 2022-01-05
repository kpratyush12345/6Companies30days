// https://practice.geeksforgeeks.org/problems/squares-in-nn-chessboard1801/1

class Solution
{
public:
    long long squaresInChessBoard(long long n)
    {
        // code here
        return (n * (n + 1) / 2) * (2 * n + 1) / 3;
    }
};