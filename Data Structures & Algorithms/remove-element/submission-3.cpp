class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        size_t i {0};
        size_t n{nums.size()};
        while(i < n)
        {
            if(nums[i] == val)
            {
                nums[i] = nums[n-1];
                --n;
            }
            else
            {
                ++i;
            }
        }
        return n;
    }
};