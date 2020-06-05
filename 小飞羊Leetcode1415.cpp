class Solution {
private:
    void helper(string tmp, string & res, int n, int & k) {
        if (k < 0) {
            return;
        }
        
        if (n == 0) {
            if (--k == 0) {
                res = tmp;
            }
            return;
        }
        
        for (auto ch = 'a'; ch <= 'c'; ++ch) {
            if (tmp.length() != 0 && tmp.back() == ch) {
                continue;
            }
            tmp.push_back(ch);
            helper(tmp, res, n - 1, k);
            tmp.pop_back();
        }
    }
public:
    string getHappyString(int n, int k) {
        string tmp;
        string res;
        
        helper(tmp, res, n, k);
        return k > 0 ? "" : res;
    }
};