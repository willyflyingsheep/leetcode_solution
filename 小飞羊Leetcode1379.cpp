/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    TreeNode* walkTogether(TreeNode* curr, TreeNode* cloned_curr, TreeNode* target) {
        if (curr == NULL) {
            return NULL;
        }
        assert(curr->val == cloned_curr->val);
        if (curr == target) {
            return cloned_curr;
        }
        TreeNode* left = walkTogether(curr->left, cloned_curr->left, target);
        if (left) {
            return left;
        }
        TreeNode* right = walkTogether(curr->right, cloned_curr->right, target);
        return right;
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return walkTogether(original, cloned, target);
    }
};