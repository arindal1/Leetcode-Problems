class Solution {
    public int mostWordsFound(String[] sentences) {
        int max=0, n=sentences.length;
           for(int i=0; i<n; i++)
           {
                String ans[]=sentences[i].split(" ");
                if(max<ans.length)
                    max=ans.length;
           }
        return max;
    }
}
