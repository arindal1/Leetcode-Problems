bool comp(vector<int>& a, vector<int>& b){
    if(a[0] == b[0]){
        if(a[1] == b[1]){
            return a[2] > b[2];
        } else {
            return a[1] > b[1];
        }
    }
    else {
        return a[0] > b[0];
    }
}

class Solution {
public:
    vector<int>stree;
    void update(int tidx, int s, int e, int idx, int val){
        if (s == e){
            stree[tidx] = val;
            return;
        }
        int mid = (s + e)/2;
        if (idx <= mid){
            update(2*tidx, s, mid, idx, val);
        }
        else {
            update(2*tidx+1, mid+1, e, idx, val);
        }
        stree[tidx] = max(stree[2*tidx], stree[2*tidx+1]);
    }

    int queri(int tidx, int s, int e, int l, int r){
        if (s > r or e < l){
            return -1;
        }
        else if (s >= l and e <= r){
            return stree[tidx];
        }
        int mid = (s + e)/2;
        int left_ans = queri(2*tidx, s, mid, l, r);
        int right_ans = queri(2*tidx+1, mid+1, e, l, r);

        return max(left_ans, right_ans);
    }

    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& query) {
        int n = nums1.size(); int q = query.size();
        vector<vector<int>>srtArr;
        set<int>s;
        for (int i=0;i<n;i++){
            s.insert(nums2[i]);
        }
        for (int i=0;i<q;i++){
            s.insert(query[i][1]);
        }
        map<int,int> mapping;
        int pos = 1;
        for (auto nuts:s){
            mapping[nuts] = pos++; 
        }
        pos++;
        for (int i=0;i<n;i++){
            srtArr.push_back({nums1[i], mapping[nums2[i]], nums1[i] + nums2[i]});
        }
        map<pair<int,int>, vector<int>>index;
        for(int i=0;i<q;i++){
            srtArr.push_back({query[i][0], mapping[query[i][1]], -1});
            index[{query[i][0], mapping[query[i][1]]}].push_back(i);
        }
        sort(srtArr.begin(), srtArr.end(), comp);
        stree.clear();
        stree = vector<int>(4*pos + 1, -1);
        vector<int>vp(pos+1, -1);
        vector<int>sol(q);
        for (int i=0;i<((int)srtArr.size());i++){
            int x = srtArr[i][0], y = srtArr[i][1], z = srtArr[i][2];
            if(z == -1) {
                int as = -1;
                as = queri(1, 0, pos-1, y, pos+1);
                pair<int, int> P = {x, y};
                for(int j:index[P]){
                    sol[j] = as;
                }
            }
            else {
                if (vp[y] < z) {
                    update(1, 0, pos-1, y, z);
                    vp[y] = z;
                }
            }
        }

        return sol;
    }
};
