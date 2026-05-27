class MyStack {
private:
    std::queue<int> q1;
    std::queue<int> q2;
public:
    MyStack(): q1{}, q2{} {
    }
    
    void push(int x) {
        if(q1.empty())
        {
            q1.push(x);
            while(!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
        }
        else if(q2.empty())
        {
            q2.push(x);
            while(!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }
    
    int pop() {
        if(q1.empty())
        {
            int temp = q2.front();
            q2.pop();
            return temp;
        }
        else if(q2.empty())
        {
            int temp = q1.front();
            q1.pop();
            return temp;
        }
    }
    
    int top() {
        if(q1.empty()) return q2.front();
        else return q1.front();
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */