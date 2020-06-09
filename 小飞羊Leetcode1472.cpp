class BrowserHistory {
private:
    vector<string> histories;
    int curr_view;
public:
    BrowserHistory(string homepage) {
        histories.clear();
        histories.reserve(5000);
        curr_view = 0;
        histories.push_back(homepage);
    }
    
    void visit(string url) {
        curr_view++;
        histories.erase(histories.begin() + curr_view, histories.end());
        histories.push_back(url);
    }
    
    string back(int steps) {
        curr_view -= steps;
        curr_view = curr_view < 0 ? 0 : curr_view;
        return histories[curr_view];
    }
    
    string forward(int steps) {
        curr_view += steps;
        curr_view = curr_view >= histories.size() ? histories.size() - 1 : curr_view;
        return histories[curr_view];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */