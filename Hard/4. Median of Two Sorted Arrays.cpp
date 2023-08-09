
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;
        int gap=ceil((n1+n2)/2.0);
        int i=0;
        int j=gap;
        if(n1==0)
            return n2%2?nums2[n2/2]:(nums2[n2/2]+nums2[n2/2-1])/2.0;
        if(n2==0)
            return n1%2?nums1[n1/2]:(nums1[n1/2]+nums1[n1/2-1])/2.0;
       while(gap)
       {   i=0;
           j=gap;
        while(j<n)
        {
            if(i<n1&&j<n1&&nums1[i]>nums1[j])
            swap(nums1[i],nums1[j]);
        else
            if(i<n1&&j>=n1&&nums1[i]>nums2[j-n1])
                swap(nums1[i],nums2[j-n1]);
        else 
            if(i>=n1&&j>=n1&&nums2[i-n1]>nums2[j-n1])
                 swap(nums2[i-n1],nums2[j-n1]);
        i++;
        j++;
        }
        if(gap==1)
            gap=0;
         
         gap=ceil(gap/2.0);
       }   
      if(n%2)
          return n/2<n1?nums1[n/2]:nums2[n/2-n1];
     else
         if(n/2<n1)
             return (nums1[n/2]+nums1[n/2-1])/2.0;
        else
            if((n/2-1)<n1)
               return (nums1[n/2-1]+nums2[n/2-n1])/2.0;
       else 
           return (nums2[n/2-n1]+nums2[n/2-1-n1])/2.0;
       
    }
};
