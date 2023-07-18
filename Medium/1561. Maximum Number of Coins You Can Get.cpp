class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int total=0;
        int last=piles.size()-2;
        for(int i=0;i<piles.size()/3;i++){
           total+=piles[last];
           last-=2; 
        }
        return total;
    }
};
