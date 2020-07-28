class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int k = 1e9 + 7;
        int prefix_sum = 0;
        int odd_subarrays = 0;
        int even_subarrays = 0;
        int res = 0;
        for (auto & val : arr) {
            prefix_sum += val;
            if (prefix_sum % 2 == 0) {
                res += odd_subarrays % k;
                even_subarrays++;
            } else {
                res += 1;
                res += even_subarrays % k;
                odd_subarrays++;
            }
            res %= k;
        }
        return res;
    }
};