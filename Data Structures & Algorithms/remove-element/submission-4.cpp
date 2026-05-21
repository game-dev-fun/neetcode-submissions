class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int deleted{0};
        int k{0};
        int i{0};
        while(i < nums.size())
        {
            if(nums[i] == val)
            {
                if(nums.size() - deleted - 1 > i)
                {
                    std::swap(nums[i], nums[nums.size() - deleted - 1]);
                    ++deleted;
                }
                else
                {
                    break;
                }
            }
            else
            {
                ++k;
                ++i;
            }
        }
        return k;
    }
};