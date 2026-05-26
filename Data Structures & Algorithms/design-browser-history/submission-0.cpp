class BrowserHistory {
private:
    std::vector<std::string> history;
    int currentIndex;
    int lastIndex;
public:
    BrowserHistory(string homepage) : history{}, currentIndex{0}, lastIndex{0}{
        history.push_back(homepage);
    }
    
    void visit(string url) {
        if(currentIndex == history.size()-1)
        {
            history.push_back(url);
            ++currentIndex;
        }
        else
        {
            history[++currentIndex] = url;
        }
        lastIndex = currentIndex;
    }
    
    string back(int steps) {
        if(currentIndex - steps < 0) currentIndex = 0;
        else currentIndex -= steps;
        return history[currentIndex];
    }
    
    string forward(int steps) {
        if(currentIndex + steps > lastIndex) currentIndex = lastIndex;
        else currentIndex += steps;
        return history[currentIndex];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */