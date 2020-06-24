class Solution {
private:
    int cal_four_divisors_sum(int num) {
        int sqt = sqrt(num);
        if (sqt * sqt == num) {
            return 0;
        }
        
        int sum = 1 + num;
        int count = 2;
        for (int i = 2; i <= sqt; ++i) {
            if (num % i == 0) {
                sum += i + num / i;
                count += 2;
            }
            if (count > 4) {
                return 0;
            }
        }
        if (count != 4) {
            return 0;
        }
        return sum;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for (auto num : nums) {
            // 1 <= num <= 10^5
            if (num < 6) {
                continue;
            }
            res += cal_four_divisors_sum(num);
        }
        return res;
    }
};