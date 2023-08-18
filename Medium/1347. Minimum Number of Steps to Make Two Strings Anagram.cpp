class Solution {
public:
    int minSteps(string s, string t) 
    {
        int c=0;
        int n1=s.size();
        int n2=t.size();
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        for(int i=0;i<t.size();i++)
        {
            if(m.find(t[i])!=m.end() and m[t[i]]>0)
            {
                c++;
                m[t[i]]--;
                cout<<t[i]<<endl;
            }
        }
        return n1-c;
    }
};
