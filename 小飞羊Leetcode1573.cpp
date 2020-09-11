class Solution {
public:
    int numWays(string str) {
        int k = 1e9 + 7;
        
        int count_1s = 0;
        for (auto & s : str) {
            count_1s += s == '1' ? 1 : 0;
        }
        
        // case 1 all zeros
        long n = str.length();
        if (count_1s == 0) return ((n - 1) * (n - 2) / 2) % k;
        // case 2 unable to divide
        if (count_1s % 3) return 0;
        // case 3 common case
        int budget = count_1s / 3;

        auto scanner = [&](auto it, auto ending) {
            int curr = 0;
            int res = 0;
            while (it != ending) {
                curr += *it == '1' ? 1 : 0;
                if (curr == budget) res++;
                else if (curr > budget) break;
                ++it;
            }
            return res;
        };
        
        long left = scanner(str.begin(), str.end());
        long right = scanner(str.rbegin(), str.rend());
        
        return left * right % k;
    }
};