class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> booked;
        for (auto reserved : reservedSeats) {
            booked[reserved[0]].push_back(reserved[1]);
        }
        
        int res = (n - booked.size()) * 2;
        for (auto booked_row : booked) {
            bool left_free = true;
            bool middle_free = true;
            bool right_free = true;
            for (auto booked_seat : booked_row.second) {
                if (booked_seat >= 2 && booked_seat <= 5) left_free = false;
                if (booked_seat >= 4 && booked_seat <= 7) middle_free = false;
                if (booked_seat >= 6 && booked_seat <= 9) right_free = false;
            }
            if (left_free && right_free) {
                res += 2;
            } else if (left_free || right_free || middle_free) {
                res += 1;
            }
        }
        return res;
    }
};