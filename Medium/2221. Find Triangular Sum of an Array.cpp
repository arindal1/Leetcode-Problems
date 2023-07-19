class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        vector<int> A,B;
        A=nums;
        while(true){
            if(A.size()==1)
                break;
            else{
                B=A;
                A.clear();
                for(int i=0;i<B.size()-1;i++){
                    int C=B[i]+B[i+1];
                    if(C<10)
                        A.push_back(C);
                    else
                        A.push_back(C-10);
                }
            }
        }
        return A[0];
    }
};
