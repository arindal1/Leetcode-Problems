class Solution {
public:
    int findIndex(int val,vector<int>p){
        for(int i=0;i<p.size();i++){
            if(p[i]==val)
                return i;
        }
        return -1;
    }
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int>p(m);
        for(int i=0;i<m;i++){
            p[i]=(i+1);
        }
        for(int i=0;i<queries.size();i++){
            int org=queries[i];
            int idx=findIndex(queries[i],p);
            queries[i]=idx;
            p.erase(p.begin()+idx);
            p.insert(p.begin(),org);
        }
        return queries;
        
    }
};
