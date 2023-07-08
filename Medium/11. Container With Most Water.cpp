class Solution {
public:
    int maxArea(vector<int>& height) {
    int i = 0;
        int n = height.size();
        int j = n - 1;
        int area = 0;

        while(j > i){
            area = max(area, min(height[i],height[j]) * abs(i - j));
            if(height[i] < height[j]) i++;
            else j--;
        }

        return area;
        
    }
};
