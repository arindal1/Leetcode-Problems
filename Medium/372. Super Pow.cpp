class Solution {
public:
    int n=1337;
    int phi=1140;
    int p2=7, p1=191;
    int xq=82;
    long long modPow(int a, int exp, int p){
        a%=p;
        if (a==0) return 0;
        if (exp==0) return 1;
        if (exp==1) return a;
        int y=(exp%2==1)?a:1;
        return modPow( a*a%p , exp/2, p)*y%p;
    }

    long long Chinese_Remainder(int x1, int x2){
        long long num=xq*p2;
        long long ans=(num*x1+(1-num)*x2)% n;
        while (ans<0) 
            ans+=n;
        return ans;
    }

    int superPow(int a, vector<int>& b) {
        int s=b.size();
        int exp=0, exp1=0, exp2=0;
        for(int i=0; i<s; i++)
            exp=(b[i]+10*exp)%phi;
        exp1=exp%(p1-1);
        exp2=exp%(p2-1);
        int x1=modPow(a, exp1, p1);
        int x2=modPow(a, exp2, p2);
        return Chinese_Remainder(x1, x2); 
    }
};
