class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max{0};
        int total{0};
        for(const int i: nums)
        {
            if(i == 1)
            {
                ++total;
                if(total > max)
                    max = total;
            }
            else
            {
                total = 0;
            }
        }
        return max;

    }
};