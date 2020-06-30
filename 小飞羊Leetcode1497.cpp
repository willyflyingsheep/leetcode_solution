class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainders(k, 0);
        for (auto val : arr) {
            remainders[(val % k + k) % k]++;
        }
        
        // (0, k) pairs should be even
        if (remainders[0] & 1 != 0) {
            return false;
        }
            
        for (int r = 1; r <= k / 2; ++r) {
            if (remainders[r] != remainders[k - r]) {
                return false;
            }
        }
        return true;
    }
};