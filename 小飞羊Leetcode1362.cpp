class Solution {
public:
    vector<int> closestDivisors(int num) {
        int f1 = sqrt(num + 2);
        while (f1 > 1) {
            if ( (num + 1) % f1 == 0) {
                return {f1, (num + 1) / f1};
            } else if ( (num + 2) % f1 == 0) {
                return {f1, (num + 2) / f1};
            }
            --f1;
        }
        return {1, num + 1};
    }
};ß