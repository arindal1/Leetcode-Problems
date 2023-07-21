class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int i=edges[0][0],j=edges[0][1],k=edges[1][0],l=edges[1][1];
        vector<int> v;
        v.push_back(i);
        v.push_back(l);
        v.push_back(k);
        v.push_back(j);
        sort(v.begin(),v.end());
        for(int g=0;g<v.size()-1;g++){
            if(v[g]==v[g+1]) return v[g];
        }
        return 0;
    }
};
