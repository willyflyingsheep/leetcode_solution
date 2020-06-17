class Solution {
private:
    int collect_bouquets(vector<int>& bloomDay, int afterDays, int bouquest_size) {
        int bouquets = 0;
        int flowers = 0;
        for (auto day : bloomDay) {
            if (day > afterDays) {
                flowers = 0;
                continue;
            }
            flowers++;
            if (flowers == bouquest_size) {
                bouquets++;
                flowers = 0;
            }
        }
        return bouquets;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = 1000000000;
        int end = 0;
        for (auto val : bloomDay) {
            start = min(start, val);
            end = max(end, val);
        }
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            int bouquests = collect_bouquets(bloomDay, mid, k);
            if (bouquests < m) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        if (collect_bouquets(bloomDay, start, k) >= m) {
            return start;
        }
        
        if (collect_bouquets(bloomDay, end, k) >= m) {
            return end;
        }
        
        return -1;
    }
};