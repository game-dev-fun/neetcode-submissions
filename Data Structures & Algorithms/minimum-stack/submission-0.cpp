class MinStack {
    private:
    std::stack<std::pair<int,int>> stk;
public:
    MinStack() :stk{} {
        
    }
    
    void push(int val) {
        if(stk.empty())
        {
            stk.push({val,val});
        }
        else
        {
            stk.push({val,(stk.top().second < val )? stk.top().second : val});
        }
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};
