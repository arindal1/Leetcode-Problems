class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int step = 0, k = capacity;
        for(int i=0; i<plants.size(); i++)
        {
            if(plants[i]<=k){
                step++;
                k-=plants[i];
            }
            else{
                step+=(2*i); 
                k = capacity;
                i--;
            }
        }
        return step;
    }
};
