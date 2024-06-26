class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            if(i==0 || j==0 || i==m-1 || j==n-1)
            if(board[i][j]=='O')
            {
                q.push({i, j});
                board[i][j]='a';
            }
        }
        int v[5]={-1, 0, 1, 0, -1};
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int r=p.first+v[i];
                int c=p.second+v[i+1];
                if(r>0 && r<m && c>0 && c<n && board[r][c]=='O')
                {
                    q.push({r, c});
                    board[r][c]='a';
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='a')
                board[i][j]='O';
                else if(board[i][j]=='O')
                board[i][j]='X';
            }
        }
    }
};
