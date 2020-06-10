class Solution {
private:
    void update(vector<int>& BITree, int idx, int changeVal) {
        while (idx < BITree.size()) {
            BITree[idx] += changeVal;
            idx += (idx & -idx);
        }
    }
    
    int query(vector<int>& BITree, int idx) {
        int prefixSum = 0;
        while (idx > 0) {
            prefixSum += BITree[idx];
            idx -= (idx & -idx);
        }
        return prefixSum;
    }
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> BITree(2 * m + 1, 0);
        vector<int> new_array(2 * m + 1, 0);
        for (int i = 1; i <=m; ++i) {
            new_array[i] = i + m;
            update(BITree, i + m, 1);
        }
        
        vector<int> res;
        res.reserve(queries.size());
        for (auto q : queries) {
            int how_many_numbers_before = query(BITree, new_array[q]) - 1; 
            res.push_back(how_many_numbers_before);
            // reset by minusing 1
            update(BITree, new_array[q], -1);
            // update the new position
            update(BITree, m, 1);
            new_array[q] = m;
            --m;
        }
        return res;
    }
};