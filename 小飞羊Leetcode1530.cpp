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
    vector<int> helper(TreeNode* curr, int distance, int & res) {
        vector<int> heights(distance);
        if (curr == NULL) {
            return heights;
        }
        if (curr->left == NULL && curr->right == NULL) {
            heights[1] += 1; // this is a leaf node
            return heights;
        }
        
        vector<int> left_heights = helper(curr->left, distance, res);
        vector<int> right_heights = helper(curr->right, distance, res);
        
        for (int l = 1; l < distance; ++l) {
            for(int r = 1; l + r <= distance; ++r) {
                res += left_heights[l] * right_heights[r];
            }
        }
        
        for (int h = distance - 1; h > 0; --h) {
            heights[h] = left_heights[h - 1] + right_heights[h - 1];
        }
        return heights;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        if (distance == 1) {
            return 0;
        }
        assert(distance > 1);
        int res = 0;
        helper(root, distance, res);
        return res;
    }
};