class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        for(int i{0}; i < arr.size() -1; ++i)
        {
           int largest {*std::max_element(arr.begin() + i + 1, arr.end())};
           arr[i] = largest;
        }
        arr.back() = -1;
        return arr;

    }
};