class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::vector<std::pair<int,int>> vec;
        int sum{0};
        for(size_t i{0}; i < operations.size(); ++i)
        {
            if(operations[i] == "D")
            {
                int doub{vec.back().first * 2};
                sum += doub;
                vec.push_back({doub, sum});
            }
            else if (operations[i] == "+")
            {
                int add{vec.back().first + vec[vec.size() - 2].first};
                sum += add;
                vec.push_back({add, sum});
            }
            else if(operations[i] == "C")
            {
                sum -= vec.back().first;
                vec.pop_back();
            }
            else
            {
                int num {std::stoi(operations[i])};
                sum += num;
                vec.push_back({num, sum});
            }
        }
        return sum;

    }
};