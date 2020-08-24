class Solution {
private:
    int count_1s(int num) {
        int count = 0;
        for (int i = 0; i < 32; ++i) {
            if ((1 << i) & num) {
                count++;
            }
        }
        return count;
    }
public:
    int minOperations(vector<int>& nums) {
        int op1 = 0;
        int op2 = 0;
        for (auto num : nums) {
            if (num) {
                op1 += count_1s(num);
                op2 = max(op2, (int)log2(num));
            }
        }
        return op1 + op2;
    }
};