class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int res = 0;
        while (k) {
            int l = 1;
            int r = 1;
            while (r <= k) {
                int next_r = r + l;
                int next_l = r;
                r = next_r;
                l = next_l;
            }
            k -= l;
            ++res;
        }
        return res;
        
    }
};