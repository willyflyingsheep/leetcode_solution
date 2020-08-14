class Solution {
public:
    int minInsertions(string s) {
        int need_rbracket = 0; // how many ')' are needed
        int insert_left = 0;
        for (auto ch : s) {
            if (ch == '(') {
                if (need_rbracket & 1) {
                    insert_left++;
                    need_rbracket++;
                } else {
                    need_rbracket += 2;
                }
            } else if(ch == ')') {
                if (need_rbracket == 0) {
                    // need a '('
                    insert_left++;
                    need_rbracket++;
                } else {
                    need_rbracket--;
                }
            } else {
                assert(false);
            }
        }
        
        int insert_right = need_rbracket;
        return insert_left + insert_right;
    }
};