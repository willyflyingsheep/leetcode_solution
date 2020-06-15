class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int right = 0;
        int left = 0;
        int sum = 0;
        int res = INT_MAX;
        
        // prev_left prev_right
        pair<int, int> prev_smallest_window(-1, -1);
        while(right < arr.size()) {
            sum += arr[right];
            while (sum > target) {
                sum -= arr[left];
                ++left;
            }
            if (sum == target) {
                if (prev_smallest_window.second != -1 && prev_smallest_window.second < left) {
                    res = min(res, 
                              (right - left + 1) + 
                              (prev_smallest_window.second - prev_smallest_window.first + 1)
                             );               
                }
                if (prev_smallest_window == make_pair(-1, -1)
                    || right - left < prev_smallest_window.second - prev_smallest_window.first) {
                    prev_smallest_window.first = left;
                    prev_smallest_window.second = right;
                }
            }   
            ++right;
        }
    
        return res == INT_MAX ? -1 : res;
    }
};