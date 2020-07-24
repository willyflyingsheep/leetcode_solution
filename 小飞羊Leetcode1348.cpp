class TweetCounts {
private:
    unordered_map<string, set<int>> histories;
    unordered_map<string, int> intervals {
        {"minute", 60},
        {"hour",   60 * 60},
        {"day",    60 * 60 * 24}
    };
public:
    TweetCounts() {
        histories.clear();
        histories.reserve(10000);
    }
    
    void recordTweet(string tweetName, int time) {
        histories[tweetName].insert(time);
        return;
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        assert(intervals.count(freq));
        assert(endTime >= startTime);
        if (!histories.count(tweetName)) return {};
        
        int interval = intervals[freq];
        vector<int> res((endTime - startTime) / interval + 1, 0);
        
        auto left = histories[tweetName].lower_bound(startTime);
        auto right = histories[tweetName].upper_bound(endTime);
        while (left != right) {
            res[(*left - startTime) / interval]++;
            ++left;
        }
        return res;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */