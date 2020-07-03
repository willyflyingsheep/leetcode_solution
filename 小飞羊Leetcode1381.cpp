class CustomStack {
private:
    vector<int> vc;
    int maxSize;
public:
    CustomStack(int maxSize_) {
        maxSize = maxSize_;
        vc.clear();
        vc.reserve(maxSize);
    }
    
    void push(int x) {
        if (vc.size() == maxSize) {
            return;
        }
        vc.push_back(x);
    }
    
    int pop() {
        if (vc.empty()) {
            return -1;
        }
        int res = vc.back();
        vc.pop_back();
        return res;
    }
    
    void increment(int k, int val) {
        k = std::min(static_cast<size_t>(k), vc.size());
        for (int i = 0; i < k; ++i) {
            vc[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */