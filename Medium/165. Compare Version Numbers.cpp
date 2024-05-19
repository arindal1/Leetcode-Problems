 class Solution {
 public:
 int compareVersion(string version1, string version2) {
    vector<string> v1 = removedots(version1, '.');
	vector<string> v2 = removedots(version2, '.');
    int i=0, j=0;
    
    while (i<v1.size() and j<v2.size()) {
        int e1 = stoi(v1[i++]);
        int e2 = stoi(v2[j++]);
        if(e1>e2)
            return 1;
        else
            if(e1<e2)
                return -1;
    }
    while (i<v1.size())
        if(stoi(v1[i++])>0)
            return 1;
    while (j<v2.size())
        if(stoi(v2[j++])>0)
            return -1;
    return 0;
    }
    vector<string> removedots(string str, char dot) {
    vector<string> preprocessed;
    stringstream ss(str);
    string i;
    while (getline(ss, i, dot))
        preprocessed.push_back(i);
    return preprocessed;
    }
};
