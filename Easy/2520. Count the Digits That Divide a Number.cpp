class Solution {
public:
    int countDigits(int num) {
        int val, temp=num, c=0;

        while(temp!=0)
        {
            val=temp%10;
            if(num%val==0)
                c++;
            temp=temp/10;
        }
        return c;
    }
};
