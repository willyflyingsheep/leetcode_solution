class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int maxHorizontalDist = max(horizontalCuts[0], h - horizontalCuts.back());
        int maxVerticalDist = max(verticalCuts[0], w - verticalCuts.back());
        
        for (int i = 1; i < horizontalCuts.size(); ++i) {
            maxHorizontalDist = max(maxHorizontalDist, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        for (int i = 1; i < verticalCuts.size(); ++i) {
            maxVerticalDist = max(maxVerticalDist, verticalCuts[i] - verticalCuts[i - 1]);
        }
        
        return (long)maxHorizontalDist * maxVerticalDist % (1000000000 + 7);
    }
};