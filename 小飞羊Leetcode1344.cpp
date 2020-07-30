class Solution {
public:
    double angleClock(int hour, int minutes) {
        double degree_per_minute = 360 / 60;
        double degree_per_hour = 360 / 12;
        
        double minutes_degree = minutes * degree_per_minute;
        
        double hour_pos = hour + (double)minutes / 60;
        double hours_degree = hour_pos * degree_per_hour;
        
        return min(abs(minutes_degree - hours_degree),
                   360 - abs(minutes_degree - hours_degree));
    }
};