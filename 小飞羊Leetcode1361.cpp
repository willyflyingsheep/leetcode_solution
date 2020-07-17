class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegrees(n, 0);
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1 && indegrees[leftChild[i]]++ >= 1) return false;
            if (rightChild[i] != -1 && indegrees[rightChild[i]]++ >= 1) return false;
        }
        
        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (indegrees[i] == 0) {
                if (root != -1) {
                    return false;
                } else {
                    root = i;
                }
            }
        }
        
        if (root == -1) {
            return false;
        } else if ( n != 1 && leftChild[root] == -1 && rightChild[root] == -1) {
            return false;
        }
        
        return true;
    }
};
