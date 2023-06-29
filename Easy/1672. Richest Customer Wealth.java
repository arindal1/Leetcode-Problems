/*1672. Richest Customer Wealth
You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth. */


class Solution {
    public int maximumWealth(int[][] accounts) {
        int n=accounts.length;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int tsum=0;
            for(int j=0;j<accounts[0].length;j++)
            {
                tsum+=accounts[i][j];
            }
            if(tsum>sum)
                sum=tsum;
        }
        return sum;
    }
}
