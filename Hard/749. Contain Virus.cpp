class cluster
{
    public:
        set<pair<int,int>> c;
        set<pair<int,int>> uc;
        int wcnt = 0;
    
};
class Solution {
public:
    
    void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &vis, cluster &cl)
    {
        if(i == grid.size() || i < 0 || j < 0 || j == grid[0].size()||vis[i][j]||grid[i][j] == -1)
        {
            return;
        }
        if(grid[i][j] == 0)
        {
            cl.wcnt++;
            cl.uc.insert({i,j});
            return;
        }
        cl.c.insert({i,j});
        vis[i][j] = true;
        dfs(grid,i+1,j,vis,cl);
        dfs(grid,i-1,j,vis,cl);
        dfs(grid,i,j+1,vis,cl);
        dfs(grid,i,j-1,vis,cl);
    }

    int containVirus(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        while(1)
        {
            vector<vector<bool>> vis(n,vector<bool>(m));
            auto comp=[](const cluster& A,const cluster& B)
            { 
                return A.uc.size()<B.uc.size();
            };
            priority_queue<cluster,vector<cluster>, decltype(comp)> pq(comp);
            for(int i = 0; i<n; i++)
            {
                for(int j = 0; j<m; j++)
                {
                    if(!vis[i][j]&&grid[i][j] == 1)
                    {
                        cluster c;
                        dfs(grid,i,j,vis,c);
                        pq.push(c);

                    }
                }
            }
            if(pq.size()==0)
            break;
            cluster k = pq.top();
            pq.pop();
            for(auto x: k.c)
            {
                grid[x.first][x.second] = -1;
            }
            ans += k.wcnt;
            while(!pq.empty())
            {
                cluster k1 = pq.top();
                pq.pop();
                for(auto x: k1.uc)
                {
                    grid[x.first][x.second] = 1;
                }   
            }
        }
        return ans;
    }
};
