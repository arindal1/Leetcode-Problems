class Solution {
    public int[] findArray(int[] pref) {
        int[] res = new int[pref.length];
        for (int i = 0, j = 1; i < pref.length - 1; i++, j++) {
            int storeValue = pref[j];
            res[j] = pref[i] ^ pref[j];
        }
        res[0] = pref[0];
        return res;
    }
}
