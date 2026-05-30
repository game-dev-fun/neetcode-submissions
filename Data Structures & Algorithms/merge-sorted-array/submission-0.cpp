class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i{0}; i < n; ++i)
        {
            int j = m-1+i;
            while(j >= 0 && nums2[i] < nums1[j])
            {
                nums1[j+1] = nums1[j];
                --j; 
            }
            nums1[j+1] = nums2[i];
        }
    }
};