class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int, int>> choices;
        choices.reserve(restaurants.size());
        for (auto & r : restaurants) {
            if ( (veganFriendly && r[2] == 0) || 
                 (r[3] > maxPrice) || 
                 (r[4] > maxDistance) ) {
                continue;
            }
            choices.push_back({r[1], r[0]});
        }
        
        sort(choices.begin(), choices.end(), greater<pair<int, int>>());
        
        vector<int> res;
        res.reserve(choices.size());
        for (auto & c : choices) {
            res.push_back(c.second);
        }
        return res;
    }
};