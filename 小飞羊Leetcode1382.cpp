class Solution {
private:
    vector<int> vc; // 有序数组
    void inorder_traversal(TreeNode* curr) {
        if (curr == NULL) {
            return;
        }
        
        inorder_traversal(curr->left);
        vc.push_back(curr->val);
        inorder_traversal(curr->right);
    }
    
    TreeNode* buildBST(int start, int end) {
        if (start > end) {
            return NULL;
        }
        
        int mid = start + (end - start) / 2;
        TreeNode* curr = new TreeNode(vc[mid]);
        curr->left = buildBST(start, mid - 1);
        curr->right = buildBST(mid + 1, end);
        return curr;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vc.clear();
        inorder_traversal(root);
        return buildBST(0, vc.size() - 1);
    }
};