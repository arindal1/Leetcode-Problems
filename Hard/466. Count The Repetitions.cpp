class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len1=s1.size(),len2=s2.size();
        vector<int>inc(len2,0);
        for(int i=0;i<len2;i++){
            int ptr1=0,ptr2=i;
            while(ptr1<len1){
                if(s1[ptr1]==s2[ptr2%len2]){
                    ptr1++;
                    ptr2++;
                }
                else ptr1++;
            }
            inc[i]=ptr2-i;
        }
        int ptr=0,mx_match_len=0;
        for(int i=1;i<=n1;i++){
            mx_match_len+=inc[ptr];
            ptr+=inc[ptr];
            ptr%=len2;
        }
        return mx_match_len/(n2*len2);
    }
};
