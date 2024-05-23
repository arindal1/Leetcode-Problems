class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        int m=a.size(),n=a[0].size();
        int i=0,j=n-1;

        while(i<m && j>=0)
        {
            if(a[i][j]==t)
            return 1;

            if(t>a[i][j])
                i++;
            else
                j--;
        }

        return 0;
    }
};
