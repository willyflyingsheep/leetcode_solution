class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        //step1: find median
        int medium_index = (arr.size() - 1) / 2;
        nth_element(arr.begin(), arr.begin() + medium_index, arr.end());
        int m = arr[medium_index];
        
        //step2: sort, write your own comparator
        auto cmp = [&m](int a, int b) {
            return abs(a - m) == abs(b - m) ? a > b : abs(a - m) > abs(b - m);
        };
        
        sort(arr.begin(), arr.end(), cmp);
        
        return vector<int> (arr.begin(), arr.begin() + k);
    }
};