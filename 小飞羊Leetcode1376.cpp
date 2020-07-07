class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // step1: build graph maps
        vector<vector<int>> employees(n);
        for (int e = 0; e < manager.size(); ++e) {
            if (manager[e] == -1) {
                continue;
            }
            employees[manager[e]].push_back(e);
        }

        // step2: queue and visited set
        queue<pair<int, int>> q;
        unordered_set<int> visited;
        q.push(make_pair(headID, informTime[headID]));
        visited.insert(headID);

        // step3: walk BFS
        int res = 0;
        while (!q.empty()) {
            auto boss = q.front();
            q.pop();
            int id = boss.first;
            int time = boss.second;
            
            if (employees[id].empty()) {
                continue;
            }
            res = max(res, time);
            for (auto next : employees[id]) {
                if (visited.count(next)) {
                    continue;
                }
                q.push(make_pair(next, time + informTime[next]));
                visited.insert(next);
            }
            
        }
        return res;
    }
};