class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res = 0;
        int sum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            if (i < k - 1) {
                continue;
            }
            
            res += sum >= threshold * k ? 1 : 0;
            sum -= arr[i - k + 1];
        }
        return res;
    }
};