class BrowserHistory {
    private:
    std::stack<std::string> backStack;
    std::stack<std::string> frontStack;
    std::string current;

public:
    BrowserHistory(string homepage): backStack{}, frontStack{}{
        current = homepage;
    }
    
    void visit(string url) {
        backStack.push(current);
        current = url;
        frontStack = {};
    }
    
    string back(int steps) {
        while(steps && !backStack.empty())
        {
            frontStack.push(current);
            current = backStack.top();
            backStack.pop();
            --steps;
        }
        return current;
    }
    
    string forward(int steps) {
       while(steps && !frontStack.empty())
       {
            backStack.push(current);
            current = frontStack.top();
            frontStack.pop();
            --steps;
       }
       return current;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */