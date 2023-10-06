class Solution {
public:
    string nearestPalindromic(string n) {
        if (n.size() == 1) return string(1, n[0] == '0' ? '1' : n[0] - 1);
        long num = stol(n);
        long p1 = static_cast<long>(pow(10, n.size() - 1) - 1l);
        long p2 = static_cast<long>(pow(10, n.size()) + 1l);

        int l = 0, r = n.size() - 1;
        bool notPalin = false;
        while (l < r) {
            if (n[l] != n[r]) notPalin = true;
            n[r--] = n[l++];
        }
        long p3 = notPalin ? stol(n) : 0;

        string temp = n.substr(0, r + 1);
        temp = to_string(stol(temp) + 1l);
        string temp2{temp};
        if (n.size() % 2 == 1) temp2.pop_back();
        reverse(temp2.begin(), temp2.end());
        temp += temp2;
        long p4 = stol(temp);

        temp = n.substr(0, r + 1);
        temp = to_string(stol(temp) - 1l);
        temp2 = temp;
        if (n.size() % 2 == 1) temp2.pop_back();
        reverse(temp2.begin(), temp2.end());
        temp += temp2;
        long p5 = stol(temp);   

        array<long, 5> arr{p1, p2, p3, p4, p5};
        sort(arr.begin(), arr.end(), [&num](const long& n1, const long& n2) {
            auto diff1 = abs(n1 - num), diff2 = abs(n2 - num);
            return diff1 == diff2 ? n1 < n2 : diff1 < diff2;
        });
        return to_string(arr[0]);
    }
};
