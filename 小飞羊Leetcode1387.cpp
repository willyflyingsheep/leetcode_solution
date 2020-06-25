class Solution {
private:
    int getPowerStep(int x) {
        int step = 0;
        while (x != 1) {
            if (x % 2 == 0) {
                x = x / 2;
            } else {
                x = 3 * x + 1;
            }
            ++step;
        }
        return step;
    }
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> vc;
        vc.reserve(hi - lo + 1);
        for (int num = lo; num <= hi; ++num) {
            vc.push_back(make_pair(getPowerStep(num), num));
        }
        
        assert(lo + k - 1 <= hi);
        nth_element(vc.begin(), vc.begin() + k - 1, vc.end());
        return vc[k - 1].second;
    }
};