class Solution {
private:
    string s;
    int k;
    int dp[10][6][6][20][2][2];
    int get() {
        memset(dp , -1 , sizeof(dp));
        return rec(0, 0, 0, 0, 0, 1);
    }
    int rec(int position , int oddCount , int evenCount , int number , bool numberStarted , bool tight) {
        if ((oddCount > 5) or (evenCount > 5)) {
            return 0;
        }
        if (position >= s.size()) {
            return oddCount == evenCount and numberStarted > 0 and number == 0;
        }
        if (dp[position][oddCount][evenCount][number][numberStarted][tight] != -1) {
            return dp[position][oddCount][evenCount][number][numberStarted][tight];
        }
        int ans = 0;
        int limit = tight ? s[position] - '0' : 9;
        for (int i = 0; i <= limit; i++) {
            if (numberStarted == false and i == 0) {
                ans += rec(position + 1 , oddCount , evenCount , number , (numberStarted | (i > 0)) , tight & (i == limit));
            }
            else if (i % 2 == 0) {
                ans += rec(position + 1 , oddCount , evenCount + 1 , (number * 10 + i) % k , (numberStarted | (i > 0)) , tight & (i == limit));
            }
            else {
                ans += rec(position + 1 , oddCount + 1 , evenCount , (number * 10 + i) % k , (numberStarted | (i > 0)) , tight & (i == limit));
            }
        }
        return dp[position][oddCount][evenCount][number][numberStarted][tight] = ans;
    }
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string h = to_string(high);
        this->k = k;
        this->s = h;
        int ans = get();
        low--;
        string l = to_string(low);
        int diff = h.size() - l.size();
        string ss(diff , '0');
        ss += l;
        this->s = ss;
        return ans - get();
    }
};
