class Solution {
private:
    char reverse(char ch) {
        if (ch == '0') return '1';
        if (ch == '1') return '0';
        assert(false);
        return 'N';
    }
public:
    char findKthBit(int n, int k) {
        if (n == 1) {
            return '0';
        }
        int length = 1 << n;
        int middle = length / 2;
        if (middle == k) {
            return '1';
        }
        return k < middle ? findKthBit(n - 1, k) :
                            reverse(findKthBit(n - 1, length - k));
    }
};