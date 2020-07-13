class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int k = 1e9 + 7;
        vector<int> vc;
        //assert(n == nums.size());
        vc.reserve(n * (n + 1) / 2);
        for (int i = 0; i < n; ++i) {
            int tmp = 0;
            for (int j = i; j < n; ++j) {
                tmp += nums[j] % k;
                vc.push_back(tmp);
            }
        }
        
        sort(vc.begin(), vc.end());
  
        /*
        assert(1 <= left);
        assert(left <= right);
        assert(right <= n * (n + 1) / 2);
        */
        int res = 0;
        for (int i = left - 1; i < right; ++i) {
            res += vc[i] % k;
        }
        return res;
    }
};