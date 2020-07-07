class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int res = 0;
        int running = 0;
        for (int i = 0; i < light.size(); ++i) {
            running = max(running, light[i]);
            if (i + 1 == running) {
                res++;
            }
        }
        return res;
    }
};