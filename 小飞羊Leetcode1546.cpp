class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_set<int> set{0};
        int prefix_sum = 0;
        int res = 0;
        for (auto & num : nums) {
            prefix_sum += num;
            if (set.count(prefix_sum - target)) {
                res++;
                prefix_sum = 0;
                set = {0};
            } else {
                set.insert(prefix_sum);
            }
        }
        return res;
    }
};