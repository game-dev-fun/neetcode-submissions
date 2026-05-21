class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }


        int count {0};
        int max {0};
        for(int i{0}; i < nums.size(); ++i)
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