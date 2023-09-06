class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int k=1;
        int top,bottom,left,right;
        vector<vector<int>> matrix(n, vector<int> (n));
        top=left=0;
        right=bottom=n-1;
        while(left<=right && top<=bottom){
            for(int i=left;i<=right;i++){
                matrix[top][i]=k++;
            }
            top++;
            for(int i=top;i<=bottom;i++){
                matrix[i][right]=k++;
            }
            right--;
            for(int i=right;i>=left;i--){
                matrix[bottom][i]=k++;
            }
            bottom--;
            for(int i=bottom;i>=top;i--){
                matrix[i][left]=k++;
            }
            left++;
        }
        return matrix;
        
    }
};
