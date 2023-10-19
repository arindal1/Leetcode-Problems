class Solution {
public:
    void Update_function(map<int,int>& help , int first , int second)
    {
        if(help.size()==0)
        {
            help[second] = second+first;
            return ;
        }
        int prev =-1;
        bool add= true ;
        for( auto it :help)
        {
            if(it.first<=second && first+second>=it.second)
            {
                if(prev!=-1)
                {
                    help.erase(prev);
                }
                prev = it.first ;
            }
            if(it.first>=second && first+second<it.second)
            {
                add= false;
                break ;
            }
        }
        if(prev!=-1)
        {
            help.erase(prev);
        }
        if(add)
        {
            help[second]= first +second;
        }
    }
    int maximum(map<int,int>& help , int y )
    {
        auto it = help.lower_bound(y);
        int ans =-1;
        while(it!=help.end())
        {
            ans= max(ans , it->second);
            it++;
        }
        return ans;
    }
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) { 
        vector<int> ans(queries.size(),-1) ;
        for(int i=0 ; i<queries.size() ;i++)
        {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end());
        vector<pair<int,int>> copy ;
        for(int i =0;i<nums1.size() ;i++)
        {
            copy.push_back({nums1[i], i});
        }
        sort(copy.rbegin(), copy.rend());
        map<int,int> help ;
        int i=0 ;
        for( int j =queries.size()-1 ;j>=0 ;j--)
        {
            int x = queries[j][0];
            int y = queries[j][1];
            int ind = queries[j][2];
            while(i<copy.size() && copy[i].first>=x)
            {
                int first = copy[i].first;
                int second = nums2[copy[i].second];     
                Update_function(help , first , second );
                i++;
            }
            ans[ind]= maximum(help , y);
        }
        return ans ;
    }
};
