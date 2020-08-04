class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        assert(arr.size() >= 2);
        int winner = arr[0];
        int win_count = 0;
        for (int i = 1; i < arr.size(); ++i) {
            if (winner < arr[i]) {
                winner = arr[i];
                win_count = 1;
            } else {
                win_count++;
            }
            if (win_count >= k) {
                return winner;
            }
        }
        return winner;
    }
};