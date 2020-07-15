class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> paths(n);
        for (int i = 0; i < edges.size(); ++i) {
            paths[edges[i][0]].push_back({edges[i][1], succProb[i]});
            paths[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        queue<pair<int, double>> q;
        vector<double> probs(n, 0.0);
        q.push({start, 1.0});
        probs[start] = 1.0;
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            for (auto next : paths[curr.first]) {
                if (next.second * curr.second > probs[next.first]) {
                    q.push({next.first, next.second * curr.second});
                    probs[next.first] = next.second * curr.second;
                }
            }
        }
        
        return probs[end];
    }
};