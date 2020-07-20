class Solution {
private:
    void dfs(vector<vector<int>> & paths, vector<int> & res,
             vector<bool> & visited, vector<int> & times, 
             string & labels, int curr) {
        if (visited[curr]) {
            return;
        }
        visited[curr] = true;
        int curr_times = times[labels[curr] - 'a']++;
        for (auto next : paths[curr]) {
            dfs(paths, res, visited, times, labels, next);
        }
        res[curr] = times[labels[curr] - 'a'] - curr_times;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> paths(n);
        for (auto edge : edges) {
            paths[edge[0]].push_back(edge[1]);
            paths[edge[1]].push_back(edge[0]);
        }
        
        vector<int> res(n);
        vector<bool> visited(n, false);
        vector<int> times(26);
        
        dfs(paths, res, visited, times, labels, 0);
        
        return res;
    }
};