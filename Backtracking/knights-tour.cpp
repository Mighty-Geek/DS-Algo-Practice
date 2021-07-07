#include <iostream>
#include <vector>
using namespace std;

void displayBoard(vector<vector<int>> chess, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << chess[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
bool isSafe(vector<vector<int>> chess, int r, int c)
{
    int n = chess.size();
    return (r >= 0 && r < n && c >= 0 && c < n && chess[r][c] == -1);
}
void printKnightsTour(vector<vector<int>> chess, int r, int c, int move)
{
    int n = chess.size();
    if (!(isSafe(chess, r, c)))
    {
        return;
    }
    else if (move == n * n)
    {
        chess[r][c] = move;
        displayBoard(chess, n);
        chess[r][c] = 0;
        return;
    }

    chess[r][c] = move;
    printKnightsTour(chess, r - 2, c + 1, move + 1);
    printKnightsTour(chess, r - 1, c + 2, move + 1);
    printKnightsTour(chess, r + 1, c + 2, move + 1);
    printKnightsTour(chess, r + 2, c + 1, move + 1);
    printKnightsTour(chess, r + 2, c - 1, move + 1);
    printKnightsTour(chess, r + 1, c - 2, move + 1);
    printKnightsTour(chess, r - 1, c - 2, move + 1);
    printKnightsTour(chess, r - 2, c - 1, move + 1);
    chess[r][c] = 0;
}

int main()
{
    int n;
    cin >> n;
    int r, c;
    cin >> r >> c;
    vector<vector<int>> nums(n, vector<int>(n, -1));
    printKnightsTour(nums, r, c, 1);
    return 0;
}
