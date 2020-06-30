class Solution {
public:
    int kthFactor(int n, int k) {
        int sqt = sqrt(n);
        vector<int> factors;
        for (int i = 1; i <= sqt; ++i) {
            if (n % i == 0) {
                factors.push_back(i);
                if (--k == 0) {
                    return i;
                }
            }
        }
        
        if (sqt * sqt == n) {
            k += 1;
        }
        
        if (k > factors.size()) {
            return -1;
        }
        
        return n / *(factors.rbegin() + k - 1);
    }
};