class Solution {
public:
#define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    bool validIndex(int m, int n, int r, int c)
    {
        return r < m && r >= 0 && c < n && c >= 0;
    }

vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {1, -1, 0, 0};

bool backtracking(const vector<vector<char>> &board, vector<vector<bool>> &vis, const string &trgt,
                  const int &m, const int &n, int i, int j, string s)
{
    if (s.length() > trgt.length())
        return false;
    if (s == trgt)
        return true;
    if (!validIndex(m, n, i, j))
        return false;
    if (vis[i][j])
        return false;
    vis[i][j] = true;
    bool can = false;
    for (int k = 0; k < dx.size(); k++)
    {
        if(can)
            return can; 
        if (board[i][j] == trgt[s.length()])  
            can = backtracking(board, vis, trgt, m, n, i + dx[k], j + dy[k], s + board[i][j]);
    }


    vis[i][j] = false;
    return can; 
}


    bool exist(vector<vector<char>> &board, string word)
    {
        DPSolver;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (backtracking(board, vis, word, m, n, i, j, ""))
                    return true;
        return false;
    }
};
