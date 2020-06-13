class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int x = x_center < x1 ? x1 : x_center < x2 ? x_center : x2;
        int y = y_center < y1 ? y1 : y_center < y2 ? y_center : y2;
        int dx = abs(x - x_center);
        int dy = abs(y - y_center);
        return dx * dx + dy * dy <= radius * radius;
    }
};