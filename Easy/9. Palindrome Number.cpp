Java:

if(x < 0){
}

        int reverse = 0;
        int num=x;


        while(x > 0){
            reverse = reverse*10 + x%10;
            x = x/10;
        }

        if(reverse == num)
          return true;

        return false;

C++:

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        long long reversed = 0;
        long long temp = x;

        while (temp != 0) {
            int digit = temp % 10;
            reversed = reversed * 10 + digit;
            temp /= 10;
        }

        return (reversed == x);
    }
};
