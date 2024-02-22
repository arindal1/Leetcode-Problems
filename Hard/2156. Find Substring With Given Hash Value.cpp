class Solution {
public:
    int mod;
    long long binaryExpo(long long a,long long b)
    {
        long long res = 1;
        while(b)
        {
            if(b&1)
            {
                res = ((res%mod)*(a%mod))%mod;
            }
            b>>=1;
            a = ((a%mod)*(a%mod))%mod;
        }
        return res;
    }
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        mod = modulo;
        int n = s.size();
        long long h1 = 0;
        for(int i=n-1;i>=n-k;i--)
        {
            h1 = (h1*power+s[i]-'a'+1)%mod;
        }
        int ansidx = -1;
        if(h1==hashValue)
        {
            ansidx = n-k;
        }
        int idx = n-k-1;
        int ptr1 = n-1,ptr2 = n-k-1;
        while(ptr2>=0)
        {
            h1=(h1-((s[ptr1]-'a'+1)*binaryExpo((long long)power,(long long)k-1))%mod+mod)%mod;
            h1=(h1*power+(s[ptr2]-'a')+1)%mod;
            
            if(h1==hashValue)
            {
                ansidx = idx;  
            }
            idx--;
            ptr2--;
            ptr1--;
        }
        if(ansidx+k<=s.size())
        return s.substr(ansidx,k);
        return "";
    }
};
