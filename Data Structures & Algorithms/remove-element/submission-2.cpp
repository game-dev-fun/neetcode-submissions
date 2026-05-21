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
                if(i != notValIndex) 
                    nums[notValIndex] = nums[i];
                ++notValIndex;
            }
        }
        return notValIndex;
    }
};