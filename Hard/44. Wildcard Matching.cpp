class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        int pi=0,si=0;
        int star_idx=-1,stemp_idx=-1;
        while( si<m){
            if(pi<n && (p[pi]=='?'||p[pi]==s[si])){
                si+=1;
                pi+=1;
            }
            else if(pi<n && p[pi]=='*'){
                star_idx=pi;
                stemp_idx=si;
                pi+=1;
            }
            else if(star_idx==-1){
                return false;
            }
            else{
                pi=star_idx+1;
                si=stemp_idx+1;
                stemp_idx=si;
            }
        }
        for (int i = pi; i < n; i++) {
            if (p[i] != '*') {
                return false;
            }
        }
        return true;
    }
};
