/* 1281. Subtract the Product and Sum of Digits of an Integer
Given an integer number n, return the difference between the product of its digits and the sum of its digits. */


class Solution {
    public int subtractProductAndSum(int n) {
        int sum=0, pro=1, rem, temp=n;
        for(int i = 0; temp!=0; i++)
        {
            rem=temp%10;
            pro=pro*rem;
            sum=sum+rem;
            temp=temp/10;
        }
        return pro-sum;
    }
}
