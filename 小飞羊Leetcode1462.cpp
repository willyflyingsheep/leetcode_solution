class Solution {
private:
    void buildPrerequistieTable(vector<int>& out_edges,
                                vector<vector<int>>& reverse_graphs,
                                unordered_map<int, unordered_set<int>>& table) {
        queue<int> q;
        for (int i = 0; i < out_edges.size(); ++i) {
            if (out_edges[i] == 0) {
                q.push(i);
            }   
        }

        while (!q.empty()) {
            int high_level_course = q.front();
            q.pop();
            for (auto pre : reverse_graphs[high_level_course]) {
                if (--out_edges[pre] == 0) {
                    q.push(pre);
                }
                table[pre].insert(high_level_course);                    
             }
        }
        
    }
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        //step1. 建图
        vector<vector<int>> reverse_graphs(n, vector<int>());
        vector<int> out_edges(n, 0);
        for (auto course : prerequisites) {
            reverse_graphs[course[1]].push_back(course[0]);
            out_edges[course[0]]++;
        }
        
        //step2. build big table
        unordered_map<int, unordered_set<int>> huge_table;
        buildPrerequistieTable(out_edges, reverse_graphs, huge_table);
        
        //step3. 把值直接放到big table去check 
        vector<bool> res;
        for (auto q : queries) {
            res.push_back(huge_table[q[0]].count(q[1]));
        }
        
        return res;
    }
};