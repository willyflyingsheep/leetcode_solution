class Solution {
public:
    int helper(int curr, vector<bool>& hasApple, vector<vector<int>>& graphs, vector<int>& hasVisited) {
        hasVisited[curr] = 1;
        int res = 0;
        for (auto next : graphs[curr]) {
            if (hasVisited[next]) {
                continue;
            }
            int child_res = helper(next, hasApple, graphs, hasVisited);
            if (hasApple[next] || child_res) {
                child_res += 2;
            }
            res += child_res;
        }
        return res;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graphs(n);
        vector<int> hasVisited(n);
        
        for (auto edge : edges) {
            graphs[edge[0]].push_back(edge[1]);
            graphs[edge[1]].push_back(edge[0]);
        }
        
        return helper(0, hasApple, graphs, hasVisited);
        
    }
};