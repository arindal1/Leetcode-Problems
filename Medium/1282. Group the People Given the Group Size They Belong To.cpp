class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>> mapping;
        vector<vector<int>> ans;
        for(int i=0;i<groupSizes.size();i++){
            mapping[groupSizes[i]].push_back(i);
        }
        for(auto it:mapping){
            vector<int> temp;
            int cnt=0;
            for(int i=0;i<it.second.size();i++){
                if(cnt==it.first){
                    ans.push_back(temp);
                    cnt=0;
                    temp.clear();
                }
                temp.push_back(it.second[i]);
                cnt++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
