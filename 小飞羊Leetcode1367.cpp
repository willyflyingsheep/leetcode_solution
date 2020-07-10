/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool helper(TreeNode* curr, ListNode* curr_head) {
        if (curr_head == NULL) {
            return true;
        }
        if (curr == NULL) {
            return false;
        }
        bool node = curr->val == curr_head->val;
        if (node == false) {
            return false;
        }
        bool left = helper(curr->left, curr_head->next);
        bool right = helper(curr->right, curr_head->next);
        return left || right;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (head == NULL) {
            return true;
        }
        if (root == NULL) {
            return false;
        }
        return helper(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};