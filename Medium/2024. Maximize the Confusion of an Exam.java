class Solution {
    public int maxConsecutiveAnswers(String answerKey, int k) {
        if(k>=answerKey.length())
       return answerKey.length(); 
        int i=0;
        int j=0;
        int ct=0;
        int cf=0;
        int ans=0;
        while(j<answerKey.length())
        {
            if(answerKey.charAt(j)=='T')
            ct++;
            else 
            cf++;

            while(ct>k && cf>k)
            {
              if(answerKey.charAt(i)=='T')
                ct--;
              else 
                cf--;
                i++;
            }  
         
             ans=Math.max(ans,j-i+1);
             j++;

        }
        return ans;
        
    }
}
