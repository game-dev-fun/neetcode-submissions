class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        std::vector<int> vec;
        int i{0};
        while(i < arr.size() -1)
        {
            auto largest {std::max_element(arr.begin() + i +1, arr.end())};
            auto elem {largest - (arr.begin() + i)};
            for(auto j{0}; j < elem; ++j)
            {
                vec.push_back(*largest);
            }
            i = largest - arr.begin();
        }
        vec.push_back(-1);
        return vec;
    }
};