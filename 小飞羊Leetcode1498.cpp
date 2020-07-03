class Solution {
private:
    const int k = 1e9 + 7;
public:
    int numSubseq(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        
        sort(nums.begin(), nums.end());
        
        vector<int> pow2_results(nums.size() + 1, 1);
        for (int i = 1; i <= nums.size(); ++i) {
            pow2_results[i] = (pow2_results[i - 1] * 2) % k;
        }
        
        int res = 0;
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                res = (res % k + pow2_results[r - l]) % k;
                ++l;
            } else {
                --r;
            }
        }
        return res;
    }
};