class Solution {
public:
       vector<vector<int>> onesMinusZeros(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<int> zrow(n),zcol(m),orow(n),ocol(m);
        for(int i=0;i<n;i++){
            int o=0,z=0;
            for(int j=0;j<m;j++){
                if(a[i][j]==0)z++;
                else if(a[i][j]==1) o++;
            }
            zrow[i]=z;
            orow[i]=o;
        }
         for(int i=0;i<m;i++){
            int o=0,z=0;
            for(int j=0;j<n;j++){
                if(a[j][i]==0)z++;
                else if(a[j][i]==1) o++;
            }
            zcol[i]=z;
            ocol[i]=o;
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            vector<int> v;
            for(int j=0;j<m;j++){
                int c=0;
                c+=orow[i]+ocol[j]-zrow[i]-zcol[j];
                v.push_back(c);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
