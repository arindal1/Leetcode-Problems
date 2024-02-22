class Solution {
public:
    bool f(vector<double> &s){
        if(s.size() == 1) return abs(s[0]-24)<pow(10, -2);
        for(int i=0; i<s.size()-1; i++)
        {
            for(int j=0; j<4; j++)
            {
                double a;
                if(j==0) a = s[i]+s[i+1];
                else if(j==1) a = s[i]-s[i+1];
                else if(j==2) a = s[i]*s[i+1];
                else a = s[i]/s[i+1];
                vector<double> t;
                for(int k=0; k<s.size(); k++)
                {
                    if(k!=i && k!=i+1) t.push_back(s[k]);
                    else if(k==i) t.push_back(a);
                }
                if(f(t)) return true;
            }
        }
        return false;
    }

    bool pmt(vector<double> &s, vector<double> &num, int pos, int set){
        if(pos==4) return f(num);
        for(int i=0; i<4; i++)
        {
            if(set&(1<<i)) continue;
            num[pos] = s[i];
            if(pmt(s, num, pos+1, set|(1<<i))) return true;
        }
        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> s(4), num(4);
        for(int i=0; i<4; i++) s[i] = cards[i];
        return pmt(s, num, 0, 0);
    }
};
