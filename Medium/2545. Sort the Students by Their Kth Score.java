class Solution {
    void fillArray(int[][] score, int[][] temp, int n, int t, int idx) {
        for (int i = 0; i < n; i++)
            temp[t][i] = score[idx][i];
    }

    void merge(int[][] score, int n, int l, int mid, int r, int k) {
        int p = l, q = mid + 1;
        int[][] temp = new int[r - l + 1][n];
        int t = 0;
        while (p <= mid && q <= r) {
            if (score[p][k] > score[q][k]) {
                fillArray(score, temp, n, t, p);
                p++;
                t++;
            } 
            else {
                fillArray(score, temp, n, t, q);
                q++;
                t++;
            }
        }
        while (p <= mid) {
            fillArray(score, temp, n, t, p);
            p++;
            t++;
        }
        while (q <= r) {
            fillArray(score, temp, n, t, q);
            q++;
            t++;
        }

        // copy back to score array
        for (int i = l, h = 0; i <= r; i++, h++) 
            for (int j = 0; j < n; j++) 
                score[i][j] = temp[h][j];
    }

    void mergeSort(int[][] score, int n, int l, int r, int k) {
        if (l >= r) return;

        int mid = l + (r - l) / 2;
        mergeSort(score, n, l, mid, k);
        mergeSort(score, n, mid + 1, r, k);
        merge(score, n, l, mid, r, k);
    }

    public int[][] sortTheStudents(int[][] score, int k) {
        int m = score.length, n = score[0].length;
        mergeSort(score, n, 0, m - 1, k);
        return score;
    }
}
