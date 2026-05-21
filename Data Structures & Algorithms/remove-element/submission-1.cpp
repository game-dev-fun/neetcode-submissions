class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(!nums.size()) 
            return 0;
        int notValIndex {0};
        for(int i {0}; i< nums.size(); ++i)
        {
            if(nums[i] != val)
            {
                nums[notValIndex++] = nums[i];
            }
        }
        return notValIndex;
    }
};