const string CDEND = "]]>";
const string CDBEG = "![CDATA[";

class Solution {
public:
    bool eq(const string& s, int i, const string& subs) {
        const int n = s.size(), k = subs.size();
        if (i+k > n) return 0;
        for (int j = 0; j < k; ++j) if (subs[j] != s[i+j]) return 0;
        return 1;
    }
    bool isValid(string code) {
        if (*code.begin() != '<') return 0;
        stack<string> tags;
        int i = 1, n = code.size(), j, c;
        goto beg;

        beg:
        for (c = 0; c < 9 && i < n && code[i] >= 'A' && code[i] <= 'Z'; ++i) ++c;
        if (i == n || !c || code[i] != '>' || n-c-3 < 0 || 1 + c > n ||
            code.substr(code.length()-c-3) != "</" + code.substr(1,c) + ">"
            )
            return 0;
        n -= c + 3;
        ++i; 
        goto content;

        content:
        while (i < n && code[i] != '<') ++i;
        if (i == n) return tags.empty();
        ++i;
        goto tagname;

        cltag:
        if (tags.empty() || !eq(code,i,tags.top())) return 0;
        i += tags.top().size() + 1; tags.pop();
        goto content;

        cdata:
        while (i < n && !eq(code, i, CDEND)) ++i;
        if (i == n) return 0;
        i += CDEND.size();
        goto content;

        tagname:
        if (code[i] == '/') {++i; goto cltag;}
        if (eq(code, i, CDBEG)) {i += CDBEG.size(); goto cdata;}
        j = i;
        for (c = 0; c < 9 && i < n && code[i] >= 'A' && code[i] <= 'Z'; ++i) 
            ++c;
        if (i == n || code[i] != '>' || !c) return 0;
        tags.push(code.substr(j,c));
        ++i; 
        goto content;

        return 42;
    }
};
