class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stk;
        for(size_t i {0}; i < s.size(); ++i)
        {
            if(s[i] == '[' || s[i] == '{' || s[i] == '(')
            {
                stk.push(s[i]);
            }
            else if(s[i] == ']')
            {
                if(!stk.empty() && stk.top() == '[')
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
             else if(s[i] == '}')
            {
                if(!stk.empty() && stk.top() == '{')
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
             else if(s[i] == ')')
            {
                if(!stk.empty() && stk.top() == '(')
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};
