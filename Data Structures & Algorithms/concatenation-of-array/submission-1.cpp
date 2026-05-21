class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        const size_t n{nums.size()};
        std::vector<int> concat(n*2);
        for(size_t i{0}; i < nums.size(); ++i)
        {
            concat[i] = nums[i];
            concat[n + i] = nums[i];
        }
        return concat;
    }
};