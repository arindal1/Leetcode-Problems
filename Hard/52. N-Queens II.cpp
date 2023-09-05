class Solution {
public:
    int n;
    int f (int row, vector<bool> &u, vector<bool> &ul, vector<bool> &ur){
        if(row == n) return 1;
        int count = 0;
        for(int col = 0; col < n; ++col){
            if(u[col] && ul[n-1+row-col] && ur[row+col]){
                u[col] = false;
                ul[n-1+row-col] = false;
                ur[row+col] = false;
                count += f(row+1, u, ul, ur);
                u[col] = true;
                ul[n-1+row-col] = true;
                ur[row+col] = true;
            }
        }
        return count;
    }
    int totalNQueens(int N) {
        n = N;
        vector<bool> u(n, true), ul(2*n-1, true), ur(2*n-1, true);
        return f (0, u, ul, ur);
    }
};
