class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int,int> s_map;
        vector<string> result;

        if ( s.length() <= 10 )
            return {};

        int len = s.length() - 9;
        int code = 0;
        for ( int i = 0; i < len ; ++i ) {
            if ( i == 0 ) {
                for ( int j = 0 ; j < 10 ; ++j ) {
                    code <<= 2;
                    switch ( s[j] ) {
                    case 'A': break;
                    case 'C': code |= 1; break;
                    case 'G': code |= 2; break;
                    case 'T': code |= 3; break;
                    }
                }
            }
            else {
                code <<= 2;
                code &= 0x000fffff;
                switch ( s[i+9] ) {
                case 'A': break;
                case 'C': code |= 1; break;
                case 'G': code |= 2; break;
                case 'T': code |= 3; break;
                }
            }

            if ( s_map.count(code) > 0 ) {
                if ( s_map[code] == 1 ) {
                    result.push_back(s.substr(i,10));
                    s_map[code] = 2;
                }
            }
            else
                s_map[code] = 1;
        }

        return result;
    }
};
