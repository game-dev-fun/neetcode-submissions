class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }


        size_t count {0};
        size_t max {0};
        for(size_t i{0}; i < nums.size(); ++i)
        {
            if(nums[i])
            {
                ++count;
                if(max < count) max = count;
            }
            else
            {
                count = 0;
            }
        }
        return max;
    }
};