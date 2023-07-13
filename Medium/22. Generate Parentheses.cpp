class Solution {
    vector<string> ans;
    void workfunc(int noOfOpenBracket,int noOfCloseBracket,string s)
    {
        if(noOfOpenBracket==0 && noOfCloseBracket==0)
        {
            ans.push_back(s);
            return;
        }
        if(noOfOpenBracket<noOfCloseBracket)
        {
            workfunc(noOfOpenBracket,noOfCloseBracket-1,s+')');
        }
        if(noOfOpenBracket>0)
        workfunc(noOfOpenBracket-1,noOfCloseBracket,s+'(');
    }
    
public:
    vector<string> generateParenthesis(int n) {
        workfunc(n,n,"");
        return ans;
    }
};
