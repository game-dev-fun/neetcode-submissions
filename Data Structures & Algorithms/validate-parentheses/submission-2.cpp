class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char,char> brack{ {'}','{'}, {')','('} , {']','['}};
        std::stack<char> stk;
        for(int i{0}; i < s.length(); ++i)
        {
            switch(s[i])
            {
                case '(':
                case '[':
                case '{':
                        stk.push(s[i]);
                        break;
                default: 
                {
                    if(stk.empty() || stk.top() != brack[s[i]]) 
                        return false;
                    else
                        stk.pop();
                }
            }
        }
        return stk.empty();
    }
};
