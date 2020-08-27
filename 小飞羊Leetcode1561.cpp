class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<int>());
        int res = 0;
        int idx = 1;
        int end = piles.size() - 1;
        while (idx < piles.size() && idx < end) {
            res += piles[idx];
            idx += 2;
            end -= 1;
        }
        return res;        
    }
};