class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int answer, count=0, n=nums.size();

        for( int i = 0; i<n ; i++ ){
            if(count==0){
                answer=nums[i];
                count=1;
            }else if(nums[i]==answer){
                count++;
            }else{
                count--;
            }
        }

        return answer;
    }
};
