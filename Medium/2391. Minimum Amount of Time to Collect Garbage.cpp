class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int cnt=0,last_p=0,last_g=0,last_m=0;
        for(int i=0;i<garbage.size();i++){
            for(auto c:garbage[i]){
                cnt++;
                if(c=='P')
                    last_p=i;
                else if(c=='G')
                    last_g=i;
                else
                    last_m=i;
            }
        }
        for(int i=1;i<travel.size();i++){
           travel[i]+=travel[i-1];
        }
        int ans=cnt;
        if(last_p>0) ans+=travel[last_p-1];
        if(last_g>0) ans+=travel[last_g-1];
        if(last_m>0) ans+=travel[last_m-1];
        return ans;
    }
};
