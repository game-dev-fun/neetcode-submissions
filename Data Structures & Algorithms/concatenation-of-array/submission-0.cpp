class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        std::vector<int> concat(nums.size()*2);
        for(size_t i{0}; i < nums.size(); ++i)
        {
            concat[i] = nums[i];
            concat[nums.size() + i] = nums[i];
        }
        return concat;
    }
};