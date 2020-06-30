class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int res = 0;
        int zero_count = 0; // 当前窗口内0的个数
        while (right < nums.size()) {
            if (nums[right] == 0) zero_count++;
            while (zero_count > 1 && left < right) {
                if (nums[left] == 0) zero_count--;
                left++;
            }
            res = max(res, right - left + 1);
            ++right;
        }
        return res - 1;
    }
};