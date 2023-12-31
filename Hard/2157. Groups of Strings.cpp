class UnionFind {
private:
    vector<int> parent, rank;
    int cntGrp;
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
        cntGrp = n;
    }
    
    int find(int a){
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }
    
    void unite(int a, int b){
        int x = find(a);
        int y = find(b);
        if(x == y) return;
        
        if(rank[x] >= rank[y]){
            parent[y] = x;
            rank[x] += rank[y];
        }else{
            parent[x] = y;
            rank[y] += rank[x];
        }
        cntGrp--;
    }
    
    int getGroupCnt() {
        return cntGrp;
    }
    
    int getSizeOfLargestGrp() {
        int mx = 1;
        for(int i=0; i<rank.size(); i++){
            mx = max(mx, rank[i]);
        }
        return mx;
    }
};

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        int n = words.size();
        UnionFind uf(n);
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            int h = 0;
            for(auto &k: words[i]){
                h |= (1 << k-'a');
            }
            for(int j=0; j<26; j++){
                if(h & 1 << j){
                    int del = h ^ (1 << j);
                    if(mp.count(del)){
                        uf.unite(i, mp[del]);
                    }
                    for(int k=0; k<26; k++){
                        int replace = del | (1 << k);
                        if(replace != del && mp.count(replace)){
                            uf.unite(i, mp[replace]);
                        }
                    }
                }else{
                    int add = h | (1 << j);
                    if(mp.count(add)){
                        uf.unite(i, mp[add]);
                    }
                }
            }
            mp[h] = i;
        }
        int cnt = uf.getGroupCnt();
        int sz = uf.getSizeOfLargestGrp();
        return {cnt, sz};
    }
};
