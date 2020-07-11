class Solution {
public:
    string rankTeams(vector<string>& votes) {
        assert(!votes.empty());
        int candidates = votes[0].length();
        vector<vector<int>> vc(26, vector<int>(candidates, 0));
        
        //计票
        for (auto vote : votes) {
            for (int rank = 0; rank < candidate; ++rank) {
                vc[vote[rank] - 'A'][rank]++;
            }
        }
        
        //评选
        string res = votes[0];
        auto cmp = [&](char a, char b) {
            for (int rank = 0; rank < candidate; ++rank) {
                if (vc[a - 'A'][rank] == vc[b - 'A'][rank]) {
                    continue;
                }
                return vc[a - 'A'][rank] > vc[b - 'A'][rank];
            }
            return a < b;
        };
        
        sort(res.begin(), res.end(), cmp);
        return res;
    }
};