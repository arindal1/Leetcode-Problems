class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int i, max=INT_MIN;
        sort(points.begin(), points.end());
        for(i=0 ; i<points.size()-1 ; i++)
        {
            if(abs(points[i][0]-points[i+1][0])>max)
            {
                max = abs(points[i][0]-points[i+1][0]);
            }
        }
        return max;
    }
};
