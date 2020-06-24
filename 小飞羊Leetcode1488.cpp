class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> res;
        unordered_map<int, int> lake_fullness;
        // key: lake
        // value: 哪一天下雨被充满了
        set<int> dry_dates;
        for (int date = 0; date < rains.size(); ++date) {
            int lake = rains[date];
            // No Raining
            if (lake == 0) {
                res.push_back(1); // any number for representing no raining
                dry_dates.insert(date);
            
            // Raining on lake
            } else {
                res.push_back(-1); // -1 for representing raining
                // lake is in empty state
                if (!lake_fullness.count(lake)) {
                    lake_fullness[lake] = date;
                // lake is in full state
                } else {
                    auto found = dry_dates.lower_bound(lake_fullness[lake]);
                    if (found == dry_dates.end()) {
                        // no valid dry date found for this lake
                        // FLOOD!!!
                        return {};
                    }
                    res[*found] = lake;
                    dry_dates.erase(*found);
                    lake_fullness[lake] = date;
                }
            }
        }
        return res;
    }
};