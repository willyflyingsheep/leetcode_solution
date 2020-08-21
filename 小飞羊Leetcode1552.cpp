class Solution {
private:
    bool canPlaceAllBalls(vector<int>& position, int balls, int force) {
        assert(position.size());
        int lastPos = position.front();
        balls -= 1; // No matter what, the first location needs to place a ball
        for (auto & pos : position) {
            if (pos - lastPos >= force) {
                balls--;
                lastPos = pos;
            }
            if (balls == 0) {
                break;
            }
        }
        return balls == 0;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int start = 0; // min force
        int end = position.back() - position.front(); // max force
        
        while (start + 1 < end) {
            int force = start + (end - start) / 2;
            if (canPlaceAllBalls(position, m, force)) {
                start = force;
            } else {
                end = force;
            }
        }
        
        if (canPlaceAllBalls(position, m, end)) {
            return end;
        } else if (canPlaceAllBalls(position, m, start)) {
            return start;
        }
        
        return -1;
    }
};