class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
       if(arr.size() == 1) 
        arr[0] = -1;
       for(size_t i {0}; i < arr.size()-1; ++i)
       {
            int greatest {arr[i+1]};
            for(size_t j{i+2}; j < arr.size(); ++j)
            {
                if(arr[j] > greatest)
                    greatest = arr[j];
            }
            arr[i] = greatest;
       } 
       arr[arr.size()-1] = -1;
       return arr;
    }
};