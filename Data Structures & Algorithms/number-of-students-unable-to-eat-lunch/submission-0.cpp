class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circleCount {0};
        int squareCount {0};
        for(const int& i: students)
        {
            if(!i) ++circleCount;
            else ++squareCount;
        }
        for(const int& i: sandwiches)
        {
            if(i)
            {
                if(squareCount) --squareCount;
                else return circleCount;
            }
            else
            {
                if(circleCount) --circleCount;
                else return squareCount;
            }
        }
        return squareCount + circleCount;

    }
};