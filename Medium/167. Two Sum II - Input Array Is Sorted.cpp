class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int start = 0; 
        int end = numbers.size() - 1;

        vector<int> ans;

        while(start < end){
            int sum = numbers[start] + numbers[end];
            if( sum > target){
                end--;
            }
            else if(sum < target){
                start++;
            }
            else{
                ans.push_back(start+1);
                ans.push_back(end+1);
                return ans;
            }
        }

        return ans;
    }
};
