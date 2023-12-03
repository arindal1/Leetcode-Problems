class Solution {
	int[] pool;
    int poolLen;
    Random seed;
    
    public Solution(int n, int[] blacklist) {
    	Arrays.sort(blacklist);
    	this.seed = new Random();
    	this.pool = new int[n];
		this.poolLen = n - blacklist.length;
    	/* init as id map */
   		for (int i = 0; i < this.pool.length; i++) {
   			this.pool[i] = i;
   		}
   		/* two pointer to partition blacklist at pool end */
   		int poolEnd = this.pool.length-1;
   		for (int i = blacklist.length-1; i >= 0; i--) {
   			final int val = blacklist[i];
   			/* still in id map => index pool[val] */
   			/* swap with the other pointer */
   			int temp = this.pool[poolEnd];
   			this.pool[poolEnd] = this.pool[val];
   			this.pool[val] = temp;
   			poolEnd--;
   		}
   	}
   
   	public int pick() {
   		int i = this.seed.nextInt(this.poolLen);
   		return this.pool[i];
   	}
}
