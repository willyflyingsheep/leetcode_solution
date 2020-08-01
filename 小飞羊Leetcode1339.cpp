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
    int helper(TreeNode* curr, vector<int> & vc) {
        if (curr == NULL) {
            return 0;
        }
        int left_val = helper(curr->left, vc);
        int right_val = helper(curr->right, vc);
        int curr_val = curr->val + left_val + right_val;
        vc.push_back(curr_val);
        return curr_val;
    }
public:
    int maxProduct(TreeNode* root) {
        vector<int> node_sums;
        long all_node_sum = helper(root, node_sums);
        
        int k = 1e9 + 7;
        long res = 0;
        long product = 0;
        for (auto val : node_sums) {
            product = (all_node_sum - val) * val;
            res = res > product ? res : product;
        }
        return res % k;
    }
};