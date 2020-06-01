class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int take_left = 0;
        for (int i = 0; i < k; ++i) {
            take_left += cardPoints[i];
        }
        
        int take_right = 0;
        int n = cardPoints.size();
        
        int res = take_left + take_right;
        
        for (int i = 0; i < k; ++i) {
            take_right += cardPoints[n - i - 1]; 
            take_left -= cardPoints[k - i - 1];
            res = max(res, take_left + take_right);
        }
        
        return res;
    }
};