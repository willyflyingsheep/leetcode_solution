class Solution {
private:
    int find(vector<int> & father, int x) {
        if (father[x] == x) {
            return x;
        }
        return father[x] = find(father, father[x]);
    }
public:
    int maxEvents(vector<vector<int>>& events) {
        auto cmp = [&](vector<int> & e1, vector<int> & e2) {
            return e1[1] < e2[1];
        };
        
        sort(events.begin(), events.end(), cmp);
        
        int lastDate = events.back().back();
        vector<int> dates(lastDate + 2);
        iota(dates.begin(), dates.end(), 0);
        
        int res = 0;
        for (auto & e : events) {
            int x = find(dates, e[0]);
            if (x <= e[1]) {
                res++;
                dates[x] = find(dates, x + 1);
            }
        }
        return res;
    }
};