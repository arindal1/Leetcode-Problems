class Solution {
    public boolean isStrictlyPalindromic(int n) {
        int rem = 0;
        int base = 2;
        int temp = n;
        while (temp - 2 >= base) {
            StringBuilder b = new StringBuilder();
            String res = "";
            n = temp;
            while (n > 0) {
                rem = n % base;
                b.append(rem);
                n = n / base;
            }
            res = b.toString();
            if (!b.reverse().toString().equals(res)) {
                return false;
            }
            base++;
        }
        return true;
        
    }
}
