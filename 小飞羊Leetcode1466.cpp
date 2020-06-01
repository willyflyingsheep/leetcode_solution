class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int, int>>> graphs;
        for (auto & path : connections) {
            graphs[path[0]].push_back(make_pair(path[1], 1));
            graphs[path[1]].push_back(make_pair(path[0], 0));
        }
        
        queue<int> q;
        unordered_set<int> visited;
        q.push(0);
        visited.insert(0);
        int res = 0;
        
        while (!q.empty()) {
            int source = q.front();
            q.pop();
            for (auto n : graphs[source]) {
                if (visited.count(n.first)) {
                    continue;
                }
                q.push(n.first);
                visited.insert(n.first);
                res += n.second;
            }
        }
        
        return res;
    }
};