class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr=1;
        k--;
        while(k>0){
            int steps=countSteps(n,curr,curr+1);
            if(steps<=k){
                curr++;
                k-=steps;
            }
            else{
                curr*=10;
                k--;
            }
        }
        return curr;
    }
    int countSteps(long n,long start,long end){
        int steps=0;
        while(start<=n){
            steps+=min(n+1,end)-start;
            start*=10;
            end*=10;
        }
        return steps;
    }
};
