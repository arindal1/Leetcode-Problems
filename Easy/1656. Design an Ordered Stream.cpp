class OrderedStream {
public:
    map<int,string> mp;
    int count=1;
    OrderedStream(int n) {
        count=1;
    }
    vector<string> insert(int idKey, string value) {
        mp.insert({idKey,value});
        vector<string> ans;
        for (auto vl: mp){
            if (vl.first==count){
                count++;
                ans.push_back(vl.second);
            }
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
