class Solution {
private:
    bool isPP(vector<int> &vc) {
        unordered_map<int, int> mp;
        for (auto val : vc) {
            mp[val]++;
        }
        
        // count of odd value
        int ct = 0;
        for (auto it : mp) {
            if (it.second % 2 != 0) {
                ct++;
            }
            if (ct >= 2) {
                return false;
            }
            
        }
        return true; 
    }
public:
    void helper(TreeNode* curr, vector<int>& vc, int& res) {
        if (curr == NULL) {
            return;
        }
        vc.push_back(curr->val);
        if (curr->left == NULL && curr->right == NULL && isPP(vc)) {
             res++;
        }
        helper(curr->left, vc, res);
        helper(curr->right, vc, res);
        vc.pop_back();
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        //data structure
        vector<int> vc;
        int res = 0;
        
        helper(root, vc, res);

        return res;
    }
};