class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // count
        unordered_map<int, int> mp;
        for (auto val : arr) {
            mp[val]++;
        }
        
        // sort count
        vector<int> counts;
        counts.reserve(mp.size());
        for (auto it : mp) {
            counts.push_back(it.second);
        }
        sort(counts.begin(), counts.end()); 
        
        // simulation
        int res = counts.size();
        int idx = 0;
        while (k && idx < counts.size()) {
            assert(counts[idx]);
            counts[idx]--;
            if (counts[idx] == 0) {
                ++idx;
                res--;
            }
            --k;
        }
        
        return res;
    }
};