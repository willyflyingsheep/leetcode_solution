class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp1;
        for (auto val : arr) {
            mp1[val]++;
        }
        
        multiset<int> set;
        for (auto entry : mp1) {
            set.insert(entry.second);
        }
        
        int res = 0;
        int count = 0;
        for (auto it = set.rbegin(); it != set.rend(); ++it) {
            count += *it;
            res++;
            if (count * 2 >= arr.size()) {
                return res;
            }
        }
        return res;
        
    }
};