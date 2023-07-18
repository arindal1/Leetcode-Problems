class Solution {
public:
    vector<int> partitionLabels(string s) {
        int freq[26] = {};
        map<char,int> mp;
        vector<int> ans;
        int sz = 0;
        for(char&e: s) freq[e-'a']++;
        for(char&e: s){
            if(!mp.count(e)){
                if(freq[e-'a']-1) mp.insert({e,freq[e-'a']-1});
                sz += freq[e-'a'];
            }    
            else if(--mp[e] == 0) mp.erase(e);
            if(size(mp) == 0){
                ans.push_back(sz);
                sz = 0;
            }
        }
        return ans;
    }
};
