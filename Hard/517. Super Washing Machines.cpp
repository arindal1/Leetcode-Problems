class Solution {
public:
    int findMinMoves(vector<int>& a) {
        int sum=0,mx=0,n=a.size();
        for(int x:a){
            sum+=x;
        }
        if(sum%n!=0) return -1;
        sum=sum/n;
        for(int i=0;i<n;i++){
            a[i]=a[i]-sum;
            mx=max(a[i],mx);
        }
        int cnt=0;
        for(int x:a){
            cnt+=x;
            mx=max(mx,abs(cnt));
        }
        return mx; 
    }
};
