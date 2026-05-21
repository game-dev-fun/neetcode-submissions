class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        auto i{arr.begin()};
        while(i < arr.end() -1)
        {
            auto largest {std::max_element(i + 1, arr.end())};
            std::fill(i, largest, *largest);
            i = largest;
        }
       arr.back() = -1;
       return arr;
    }
};