class Solution {
public:
    vector<int> getGrtrSubseq(vector<int> nums, int requiredLength)
    {
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            while(ans.size()>0 && ans.back()<nums[i] && ((requiredLength-ans.size())<(n-i)))
                ans.pop_back();
            if(ans.size()<requiredLength)
                ans.push_back(nums[i]); 
        }
        return ans;
    }
    void pop_front(std::vector<int> &v)
    {
        if (v.size() > 0)v.erase(v.begin());
    }
    vector<int> merge(vector<int> p1, vector<int>p2, int k)
    {
        vector<int> temp;
        for(int j=0;j<k;j++)
        { 
            vector<int> temp2 = max(p1,p2);
            int fr = temp2.front();
            if(p1>p2)
                pop_front(p1);
            else
                pop_front(p2);
            temp.push_back(fr);
        }
      return temp;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        int n1=nums1.size(), n2=nums2.size();
        vector<int>res;
        for(int i=0;i<=k;i++)
        {
            if(i>n1 || k-i>n2)
                continue;
            vector<int>grtrSubseq1 = getGrtrSubseq(nums1,i);; 
            vector<int>grtrSubseq2 = getGrtrSubseq(nums2,k-i); 
            vector<int>temp = merge(grtrSubseq1,grtrSubseq2,k);      
            res = max(res, temp);
        }
        return res;
    }
};
