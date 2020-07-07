class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int t1 = left.empty() ? 0 : *max_element(left.begin(), left.end());
        int t2 = right.empty() ? n : n - *min_elementt(right.begin(), right.end());
        return max(t1, t2);
    }
};