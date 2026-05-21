class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(!nums.size() || ((nums.size() == 1) && (nums[0] == val))) 
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