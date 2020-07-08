/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    pair<int, int> helper(TreeNode* curr, int & res) {
        if (curr == NULL) {
            return make_pair(-1, -1);
        }
        pair<int, int> left = helper(curr->left, res);
        pair<int, int> right = helper(curr->right, res);
        pair<int, int> curr_result_type = make_pair(left.second + 1, right.first + 1);
        res = max(res, max(curr_result_type.first, curr_result_type.second));
        return curr_result_type;
    }
public:
    int longestZigZag(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
};